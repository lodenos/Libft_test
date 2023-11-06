#!/bin/bash

LIBFT_PATH=../Libft

PART_I=(
  ft_isalpha
  ft_isdigit
  ft_isalnum
  ft_isascii
  ft_isprint
  ft_strlen
  ft_memset
  ft_bzero
  ft_memcpy
  ft_memmove
  ft_strlcpy
  ft_strlcat
  ft_toupper
  ft_tolower
  ft_strchr
  ft_strrchr
  ft_strncmp
  ft_memchr
  ft_memcmp
  ft_strnstr
  ft_atoi
  ft_calloc
  ft_strdup
)

PART_II=(
  ft_substr
  ft_strjoin
  ft_strtrim
  ft_split
  ft_itoa
  ft_strmapi
  ft_striteri
  ft_putchar_fd
  ft_putstr_fd
  ft_putendl_fd
  ft_putnbr_fd
)

BONUS=(
  ft_lstnew
  ft_lstadd_front
  ft_lstsize
  ft_lstlast
  ft_lstadd_back
  ft_lstdelone
  ft_lstclear
  ft_lstiter
  ft_lstmap
)

function compile_test() {
  cc -Wall -Werror -Wextra -O0 \
    -I ./include -I ./${LIBFT_PATH}/include \
    ./src/*.c ./test/$1/main_test.c \
    -o ./test/$1/test.out \
    2> /dev/null
}

function run_test() {
  array=("$@")

  for ft in "${array[@]}"; do
    if compile_test $ft; then
      ./test/$ft/test.out
    else
      echo "💥 $ft - doesn't compile"
    fi
  done
}

echo "Libft Test - PART I"
run_test "${PART_I[@]}"

echo "Libft Test - PART II"
run_test "${PART_II[@]}"

echo "Libft Test - BONUS"
run_test "${BONUS[@]}"
