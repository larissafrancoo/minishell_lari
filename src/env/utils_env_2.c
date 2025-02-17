#include "../../include/minishell.h"

char *ft_find_env(char *key, char **env)
{
    int i;
    int key_len;

    if (!key || !env)
        return (NULL);    
    key_len = ft_strlen(key);
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(key, env[i], key_len) == 0 && env[i][key_len] == '=')
            return (env[i]);

        i++;
    }
    return (NULL);
}

char *ft_find_env_value(char *key, char **env)
{
    char *var;

    var = ft_find_env(key, env);
    if (var)
        return (ft_strdup(ft_strchr(var, '=') + 1));
    return (NULL);
}


void ft_free_arr(char **arr)
{
    int i;

    if (!arr)
        return;
    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

char	*ft_get_env(char *key, char **env)
{
	int	i;
	int	key_len;

	if (!env || !key)
		return (NULL);
	i = 0;
	key_len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, key_len) == 0 &&
			(key[key_len - 1] == '=' || env[i][key_len] == '='))
			return (env[i]);
		i++;
	}
	return (NULL);
}