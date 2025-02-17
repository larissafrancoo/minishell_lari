#include "../../include/minishell.h"

//msh_setps1
char *ft_set_prompt(char **env)
{
    char *prompt_string;
    char *username;
    char *cwd;
    char *prompt;

    username = ft_find_env_value("USER", env);//o username é mallocado? Se sim, onde tem o free dele?
    if (!username)
        username = "usuário";
    prompt_string = ft_strjoin(username, "@minishell:");
    //------adicionando free do username
    free(username);
    //----------------------------------
    prompt = ft_strjoin(prompt_string, "$ ");
    free(prompt_string);
    return (prompt);
}

void go_minibash(char *line, t_shell *shell)
{
    ft_executor(shell);
    if (shell->cmd)
        ft_clean_cmd(&shell->cmd);
    free(line);
}
void run_minibash_loop(t_shell *shell)
{
    char *prompt_template;
    char *aux;
    char *input;

    while (1)
    {
        prompt_template = ft_set_prompt(shell->env->var_list);
        if (!prompt_template)
            return;
        aux = readline(prompt_template);
        input = ft_strjoin(0, aux);
        free(aux);
        free(prompt_template);
        if (!input)
            ft_exit(0, shell->env, shell);
        if (!ft_str_is_space(input))
            add_history(input);
        if (ft_check_lexer(input))
            parse_input(input, shell);
        //ta estranho isso, pois e se o ft_checker não funcionar? O minibash vai rodar mesmo assim?
        go_minibash(input, shell);
    }
}