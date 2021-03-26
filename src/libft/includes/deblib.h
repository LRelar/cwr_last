/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deblib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:03:45 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/29 00:24:01 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBLIB_H
# define DEBLIB_H
//# define NDEBUG																	//Макрос переключения дебаггеров.
// # define TOFILE
# include <stdio.h>
# include <assert.h>
#endif

#ifndef NDEBUG
#ifndef  TOFILE
# define DEBst() printf("\t\033[0;31m%d\033[0m in:\t%s \t\t", __LINE__, __func__);
# define DEBend() printf("\n");
# define DEBit(x) printf("\033[1;35m%s\033[0m == %p ", #x, (x));
# define DEBintt(x) printf("\033[1;35m%s\033[0m == %d ", #x, (x));
# define DEBuintt(x) printf("\033[1;35m%s\033[0m == %u ", #x, (x));
# define DEBlt(x) printf("\033[1;35m%s\033[0m == %ld ", #x, (x));
# define DEBzt(x) printf("\033[1;35m%s\033[0m == %zu ", #x, (x));
# define DEBft(x) printf("\033[1;35m%s\033[0m == %f ", #x, (x));
# define DEBtextt(x) printf("[\033[1;35m%s\033[0m] == [%s] ", #x, (x));
# define DEBchart(x) printf("[\033[1;35m%s\033[0m] == [%c] ", #x, (x));
# define DEBmesst(name) printf("\033[1;36m%s\033[0m\t", (name));
# define DEBfunc() printf("\033[0;31m%d\033[0m \033[0;33mEntering\033[0m MY:\t\033[0;33m%s\033[0m of file \"%s\"\n", __LINE__, __func__, __FILE__);
# define DEB() printf("\t\033[0;31m%d\033[0m in:\t%s\n", __LINE__, __func__);
# define DEBex(name) printf("\033[0;32mExiting \033[0m MY:\t\033[0;32m%s\033[0m,%s\n\n", __func__, (name));
# define DEBprog() printf("\n\nENTRANCE IN \033[0;33m~~~~~~~~~~~~~~~~%s~~~~~~~~~~~~~~~~\033[0m\n", __FILE__);
# define DEBm() printf("Malloc failed at line \033[0;31m%d\033[0m in function: %s\n", __LINE__, __func__);
# define DEBi(name, x) printf("\033[0;31m%d\033[0m str in func: %s, \"\033[1;35m%s\033[0m\" adress %p\n", __LINE__, __func__, (name), (x));
# define DEBis(x) printf("\033[0;31m%d\033[0m str in func: %s, adress \"\033[1;35m%p\033[0m\"\n", __LINE__, __func__, (x));
# define DEBtext(name, x) printf("\033[0;31m%d\033[0m str in func: %s, arr:[%s] == [%s]\n", __LINE__, __func__, (name), (x));
# define DEBpar(name, x) printf("\033[0;31m%d\033[0m str in func: %s, arr:[%s]:\n[\n%s\n]\n", __LINE__, __func__, (name), (x));
# define DEBl(name, x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %zu\n", __LINE__, __func__, (name), (x));
# define DEBint(x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %d\n", __LINE__, __func__, #x, (x));
# define DEBf(x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %f\n", __LINE__, __func__, #x, (x));

#else
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
#ifndef s_debstruct
# define s_debstruct
typedef struct	s_debstruct
{
	int		fd;
	pid_t	pid;
}				t_debstruct;
#endif
extern int *telemfd;
extern pid_t *mypid;

# define DEBst() dprintf(*telemfd, "\t\033[0;31m%d\033[0m in:\t%s \t\t", __LINE__, __func__);
# define DEBend() dprintf(*telemfd, "\n");
# define DEBit(x) dprintf(*telemfd, "\033[1;35m%s\033[0m == %p ", #x, (x));
# define DEBintt(x) dprintf(*telemfd, "\033[1;35m%s\033[0m == %d ", #x, (x));
# define DEBuintt(x) dprintf(*telemfd, "\033[1;35m%s\033[0m == %u ", #x, (x));
# define DEBlt(x) dprintf(*telemfd, "\033[1;35m%s\033[0m == %ld ", #x, (x));
# define DEBzt(x) dprintf(*telemfd, "\033[1;35m%s\033[0m == %zu ", #x, (x));
# define DEBtextt(x) dprintf(*telemfd, "[\033[1;35m%s\033[0m] == [%s] ", #x, (x));
# define DEBchart(x) dprintf(*telemfd, "[\033[1;35m%s\033[0m] == [%c] ", #x, (x));
# define DEBmesst(name) dprintf(*telemfd, "\033[1;36m%s\033[0m ", (name));
# define DEBfunc() dprintf(*telemfd, "\033[0;31m%d\033[0m \033[0;33mEntering\033[0m MY:\t\033[0;33m%s\033[0m of file \"%s\"\n", __LINE__, __func__, __FILE__);
# define DEB() dprintf(*telemfd, "\t\033[0;31m%d\033[0m in:\t%s\n", __LINE__, __func__);
# define DEBex(name) dprintf(*telemfd, "\033[0;32mExiting \033[0m MY:\t\033[0;32m%s\033[0m,%s\n\n", __func__, (name));
# define DEBprog() dprintf(*telemfd, "\n\nENTRANCE IN \033[0;33m~~~~~~~~~~~~~~~~%s~~~~~~~~~~~~~~~~\033[0m\n", __FILE__);
# define DEBm() dprintf(*telemfd, "Malloc failed at line \033[0;31m%d\033[0m in function: %s\n", __LINE__, __func__);
# define DEBi(name, x) dprintf(*telemfd, "\033[0;31m%d\033[0m str in func: %s, \"\033[1;35m%s\033[0m\" adress %p\n", __LINE__, __func__, (name), (x));
# define DEBis(x) dprintf(*telemfd, "\033[0;31m%d\033[0m str in func: %s, adress \"\033[1;35m%p\033[0m\"\n", __LINE__, __func__, (x));
# define DEBtext(name, x) dprintf(*telemfd, "\033[0;31m%d\033[0m str in func: %s, arr:[%s] == [%s]\n", __LINE__, __func__, (name), (x));
# define DEBpar(name, x) dprintf(*telemfd, "\033[0;31m%d\033[0m str in func: %s, arr:[%s]:\n[\n%s\n]\n", __LINE__, __func__, (name), (x));
# define DEBl(name, x) dprintf(*telemfd, "\033[0;31m%d\033[0m str in func: %s, %s == %zu\n", __LINE__, __func__, (name), (x));
# define DEBint(name, x) dprintf(*telemfd, "\033[0;31m%d\033[0m str in func: %s, %s == %d\n", __LINE__, __func__, (name), (x));
#endif
#endif

#ifdef NDEBUG
# define DEBst() {}
# define DEBend() {}
# define DEBit(x) {}
# define DEBintt(x) {}
# define DEBuintt(x) {}
# define DEBlt(x) {}
# define DEBzt(x) {}
# define DEBft(x) {}
# define DEBtextt(x) {}
# define DEBchart(x) {}
# define DEBmesst(name) {}
# define DEBfunc() {}
# define DEB() {}
# define DEBex(name) {}
# define DEBprog() {}
# define DEBm() {}
# define DEBi(name, x) {}
# define DEBis(x) {}
# define DEBtext(name, x) {}
# define DEBpar(name, x) {}
# define DEBl(name, x) {}
# define DEBint(x) {}
# define DEBf(x) {}


#endif
