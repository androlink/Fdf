/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:21:52 by gcros             #+#    #+#             */
/*   Updated: 2024/02/28 01:10:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "put.h"

int	print_error(t_fdf_err err_code)
{
	const char	*str_err = fdf_strerr(err_code);

	if (str_err == NULL)
		return (0);
	ft_putendl_fd((char *)str_err, 2);
	return (1);
}

const char	*fdf_strerr(t_fdf_err err_code)
{
	static const char	*strs[] = {
	[nothing_append] = "good job, you exit without error",
	[bad_file] = "file can't be read",
	[bad_file_ext] = "file is not a .fdf",
	[no_file] = "you need to pass a file",
	[object_parsing] = "bad file format",
	[init_fail] = "something bad append",
	[no_parsing_func] = "parsing function not found",
	};

	if (err_code == look_errno)
		return (strerror(errno));
	if (err_code * sizeof(char *) >= sizeof(strs))
		return ("wow, you found an error");
	return (strs[err_code]);
}
