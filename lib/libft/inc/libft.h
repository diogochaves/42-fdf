#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 256
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Get the next line object
 *
 * @param fd File descriptor to read from
 * @return Read line: correct behavior || NULL: nothing else to read or an
 * error occurred
 */
char	*get_next_line(int fd);

/**
 * @brief Checks for an alphabetic character.
 *
 * @param c the char to check.
 * @return 1 if the character C falls into the tested class, and 0 if not.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks for a digit (0 through 9).
 *
 * @param c the char to check.
 * @return 1 if the character C falls into the tested class, and 0 if not.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character; it is equivalent to
 * (isalpha(c) || isdigit(c)).
 *
 * @param c the char to check.
 * @return 1 if the character C falls into the tested class, and 0 if not.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the
 * ASCII character set.
 *
 * @param c the char to check.
 * @return 1 if the character C falls into the tested class, and 0 if not.
 */
int		ft_isascii(int c);

/**
 * @brief Checks for any printable character, including space.
 *
 * @param c the char to check.
 * @return 1 if the character C falls into the tested class, and 0 if not.
 */
int		ft_isprint(int c);

/**
 * @brief Calculates the length of the string pointed to by S, excluding the
 * terminating null byte ('\0').
 *
 * @param s The string to count.
 * @return The lenght of the string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Fills the first N bytes of the memory area pointed to by S with the
 * constant byte C.
 *
 * @param s The pointer to the memory area.
 * @param c The byte to set.
 * @param n The quantity of bytes to set.
 * @return A pointer to the memory area S.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Erases the data in the N bytes of the memory starting at the location
 * pointed to by S, by writing zeroes (bytes containing '\\0') to that area.
 *
 * @param s The pointer to the memory area.
 * @param n The quantity of bytes to erase.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies N bytes from memory area SRC to memory area DEST. The memory
 * areas must not overlap.
 *
 * @param dest The pointer to the memory area DEST.
 * @param src The pointer to the memory area SCR.
 * @param n The quantity of bytes to copy.
 * @return A pointer to the memory area DEST.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies N bytes from memory area SRC to memory area DEST. The memory
 * areas may overlap.
 *
 * @param dest The pointer to the memory area DEST.
 * @param src The pointer to the memory area SCR.
 * @param n The quantity of bytes to copy.
 * @return A pointer to the memory area DEST.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copies up to (SIZE - 1) characters from the NUL-terminated string SRC
 * to DST, NUL-terminating the result.
 *
 * @param dst The pointer to the memory area DST.
 * @param src The pointer to the memory area SCR.
 * @param size The quantity of bytes to copy.
 * @return The total length of the string it tried to create (length of
 * SRC).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string SRC to the end of DST. It will
 * append at most (SIZE - strlen(DST) - 1 byte), NUL-terminating the result.
 *
 * @param dst The pointer to the memory area DST.
 * @param src The pointer to the memory area SCR.
 * @param size The quantity of bytes to append.
 * @return The total length of the string it tried to create (the initial
 * length of DST plus the length of SRC).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Convert a lowercase letter to uppercase.
 *
 * @param c The char to convert.
 * @return If C is a lowercase letter, returns its uppercase equivalent.
 * Otherwise, it returns C.
 */
int		ft_toupper(int c);

/**
 * @brief Convert a uppercase letter to lowercase.
 *
 * @param c The char to convert.
 * @return If C is a uppercase letter, returns its lowercase equivalent.
 * Otherwise, it returns C.
 */
int		ft_tolower(int c);

/**
 * @brief Locate the first occurrence of character in string.
 *
 * @param s The string to search.
 * @param c The char to find.
 * @return A pointer to the matched character or NULL if the character is not
 * found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Locate the last occurrence of character C in the string S.
 *
 * @param s The string to search.
 * @param c The char to find.
 * @return A pointer to the matched character or NULL if the character is not
 * found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the first (at most) N bytes the two strings S1 and S2.
 *
 * @param s1 The 1st string to compare.
 * @param s2 The 2nd string to compare.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if S1 is found,
 * respectively, to be less than, to match, or be greater than S2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the initial N bytes of the memory area pointed to by S for the
 * first instance of C.
 *
 * @param s The memory area to search.
 * @param c The char to find.
 * @param n The number of bytes to search.
 * @return A pointer to the matching byte or NULL if the character does not
 * occur in the given memory area
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first N bytes of the memory areas S1 and S2.
 *
 * @param s1 The 1st memmory area.
 * @param s2 The 2nd memmory area.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if S1 is found,
 * respectively, to be less than, to match, or be greater than S2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string LITTLE in
 * the string BIG, where not more than LEN characters are searched. Characters
 * that appear after a ‘\0’ character are not searched.
 *
 * @param big The string to search.
 * @param little The string to find.
 * @param len The number of chars to search.
 * @return If LITTLE is an empty string, BIG is returned; if LITTLE occurs
 * nowhere in BIG, NULL is returned; otherwise a pointer to the first character
 * of the first occurrence of LITTLE is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Converts the initial portion of the string pointed to by NPTR to int.
 * The string may begin with an arbitrary amount of white space (as determined
 * by isspace(3)) followed by a single optional '+' or '-' sign.
 *
 * @param nptr The char to convert.
 * @return The integer value.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Converts the initial portion of the string pointed to by STR to
 * provided base (2, 8, 10 or 16). The string may begin with an arbitrary 
 * amount of white space followed by a single optional '+' or '-' sign.
 *
 * @param str The string to convert.
 * @param base The base for the conversion. 
 * @return The integer value.
 */
int		ft_atoi_base(char *str, char *base);

/**
 * @brief Allocates memory for an array of NMEMB elements of SIZE bytes each.
 * The memory is set to zero.
 *
 * @param nmemb The number of elements.
 * @param size The size of each element.
 * @return If NMEMB or SIZE is 0, then it returns either NULL, or a unique
 * pointer value that can later be successfully passed to free().
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Duplicates the string S.
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string. It returns NULL if insufficient
 * memory was available.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Allocates and returns a substring from the string S. The substring
 * begins at index START and is of maximum size LEN.
 *
 * @param s The string from which to create the substring.
 * @param start  The start index of the substring in the string S.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, which is the result of the
 * concatenation of S1 and S2.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of S1 with the characters specified in
 * SET removed from the beginning and the end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by splitting S
 * using the character C as a delimiter. The array must be ended by a NULL
 * pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the
 * allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Allocates and returns a string representing the integer received as
 * an argument.
 *
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/**
 * @brief Applies the function F to each character of the string S to create a
 * new string resulting from successive applications of F.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of F. Returns
 * NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function F to each character of the string passed as
 * argument, and passing its index as first argument. Each character is passed
 * by address to F to be modified if necessary
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character C to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string S to the given file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string S to the given file descriptor, followed by a
 * newline.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer N to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Allocates and returns a new element. The variable CONTENT is
 * initialized with the value of the parameter CONTENT. The variable NEXT is
 * initialized to NULL.
 *
 * @param content The content to create the new element with.
 * @return The new element.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the element NEW at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 *
 * @param lst The beginning of the list.
 * @return Length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The beginning of the list.
 * @return Last element of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the element NEW at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Frees the memory of the element’s content using the function DEL and
 * free the element.
 *
 * @param lst The element to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Deletes and frees the given element and every successor of that
 * element, using the function DEL and free. Finally, the pointer to the list
 * is set to NULL.
 *
 * @param lst The adress of a pointer to an element.
 * @param del The adress of the function used to delete the content of the
 * element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Iterates the list LST and applies the function F to the content of
 * each element.
 *
 * @param lst The adress of a pointer to an element.
 * @param f The adress of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Creates a newlist resulting of the successive applications of the
 * function F on the list LST. The DEL function is used to delete the content
 * of an element if needed.
 *
 * @param lst The adress of a pointer to an element.
 * @param f The adress of the function used to iterate on the list.
 * @param del The adress of the function used to delete the content of an
 * element if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
