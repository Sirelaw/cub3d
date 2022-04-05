/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:10:30 by oipadeol          #+#    #+#             */
/*   Updated: 2022/01/05 15:03:17 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// The atoi() function converts the initial portion of the string pointed to
// by str to int representation.
int		ft_atoi(const char *str);
// The bzero() function writes c zeroed bytes to the string dest.  If c is
// zero, bzero() does nothing.
void	ft_bzero(void *dest, size_t c);
// The calloc() function contiguously allocates enough space for count objects
// that are size bytes of memory each and returns a pointer to the allocated 
// memory.  The allocated memory is filled with bytes of value zero.
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int a);
int		ft_isprint(int c);
int		ft_bigger(int n1, int n2);
// Returns the abs value of n
int		ft_absolute(int n);
// Allocates (with malloc(3)) and returns a string representing the integer
// received as an argument.Negative numbers are handled.
char	*ft_itoa(int n);
// Locates the first occurence of c (converted to an unsigned char) in string s.
void	*ft_memchr(const void *s, int c, size_t n);
// The memcmp() function compares byte string string1 against 
// byte string string2. Both strings are assumed to be n bytes long.
int		ft_memcmp(const char *string1, const char *string2, size_t n);
// The memcpy() function copies n bytes from memory area source to memory area
// dest. If dest and source overlap, behavior is undefined.
void	*ft_memcpy(void *dest, const void *source, size_t n);
// The memmove() function copies len bytes from string src to string dst. The 
// two strings may overlap; the copy is always done in a non-destructive manner.
void	*ft_memmove(void *dst, const void *src, size_t len);
// The memset() function writes c bytes of value b (converted to an
// unsigned char) to the string dest.
void	*ft_memset(void *dest, int b, size_t c);
// Outputs the character ’c’ to the given file descriptor.
void	ft_putchar_fd(char c, int fd);
// Outputs the string ’s’ to the given file descriptor, followed by a newline.
void	ft_putendl_fd(char *s, int fd);
// Outputs the integer ’n’ to the given file descriptor.
void	ft_putnbr_fd(int n, int fd);
// Outputs the string ’s’ to the given file descriptor.
void	ft_putstr_fd(char *s, int fd);
// Allocates (with malloc(3)) and returns an array of strings obtained by
// splitting ’str’ using the character ’c’ as a delimiter.  
char	**ft_split(char const *str, char c);
// locates the first occurrence of c (converted to a char) in the string
// pointed to by s.
char	*ft_strchr(const char *s, int c);
// allocates sufficient memory for a copy of the string s1, does the copy,
//and returns a pointer to it.
char	*ft_strdup(const char *string1);
// Applies the function f to each character of the string passed as argument,
// and passing its index as first argument.  Each character is passed byaddress
//to f to be modified if necessary
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
// Allocates (with malloc(3)) and returns a newstring, which is the result
// of the concatenation of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2);
// appends string src to the end of dst.  It will append at most
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// copies up to dstsize - 1 characters from the string src to dst,
// NUL-terminating the result if dstsize is not 0.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// computes the length of the string s.
size_t	ft_strlen(const char *s);
// Applies the function ’f’ to each character of thestring ’s’ to create a new
// string (with malloc(3))resulting from successive applications of ’f’.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Lexicographically compare two strings s1 and s2.
// Atleast one of them must be null-terminated else behaviour is undefined.
int		ft_strcmp(const char *string1, const char *string2);
// Lexicographically compare the null-terminated strings s1 and s2.
// Function compares not more than n characters.
int		ft_strncmp(const char *string1, const char *string2, size_t n);
// The strnstr() function locates the first occurrence of the null terminated
// string needle in the string haystack, not more than n chars are searched.
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
// locates the last occurrence of c (converted to a char) in the string
// pointed to by s.
char	*ft_strrchr(const char *s, int c);
// Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
// specified in ’set’ removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set);
// Allocates (with malloc(3)) and returns a substring from the string ’string’.
// The substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char const *string, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
// Converts the string str to long value depending on the base and given
// terminator (NULL in most cases)
long	ft_strtol(const char *str, char **end_ptr, int base);
// Allocates (with malloc(3)) and returns a newelement. The variable ’content’
// is initialized with the value of the parameter ’content’.
// The variable ’next’ is initialized to NULL.
t_list	*ft_lstnew(void *content);
// Adds the element ’new’ at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new);
// Counts the number of elements in a list.
int		ft_lstsize(t_list *lst);
// Returns the last element of the list.
t_list	*ft_lstlast(t_list *lst);
// Adds the element ’new’ at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new);
// Takes as a parameter an element and frees the memory of the element’s
// content using the function ’del’ given as a parameter and free the element.
void	ft_lstdelone(t_list *lst, void(*del)(void *));
// Deletes and frees the given element and every successor of that element,
// using the function ’del’ and free(3).
void	ft_lstclear(t_list **lst, void (*del)(void *));
// Iterates the list ’lst’ and applies the function’f’ to the
// content of each element.
void	ft_lstiter(t_list *lst, void (*f)(void *));
// Iterates the list ’lst’ and applies the function ’f’ to the content of each
// element. Creates a newlist resulting of the successive applications of the
// func ’f’.  The ’del’ function is used to delete the content of an element.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
// Returns the nth element of list 'lst'. First element is element 0.
t_list	*ft_lstelem(t_list *lst, int n);

#endif
