#!/bin/bash

LIBFT_PATH=../Libft

PART_I=(ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen
  ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper
  ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr
  ft_atoi ft_calloc ft_strdup)

PART_II=(ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi
  ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd)

BONUS=(ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus
  ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus
  ft_lstmap_bonus)

function compile_behavior_test() {
  cc -Wall -Werror -Wextra -std=c99 -O0 \
    -I ./include -I $LIBFT_PATH \
    -L ./ -lft \
    ./src/main_behavior_test.c \
    $2 \
    -o ./test/$1/test.out \
    #2> /dev/null
}

function run_all_behavior_test() {
  BEHAVIOR=`ls ./test/$1/behavior_test_*.c`

  echo "   \c"
  for file in ${BEHAVIOR[@]}
  do
    if compile_behavior_test $1 $file
    then
      if ./test/$1/test.out 2> /dev/null
      then
        echo "🟩\c"
      else
        echo "🟥\c"
      fi
      rm -f ./test/$1/test.out 2> /dev/null
    else
      echo "🚨\c" # "💥"
    fi
  done
  echo
}

function run_all_benchmark() {
  BENCHMARK=`ls ./test/$1/benchmark_*.c`

#  for file in ${BENCHMARK[@]}
#  done
}

function compile_as_lib() {
  cc -O0 -c $LIBFT_PATH/*.c
  ar rc libft.a *.o
  rm -f *.o
}

function run_test() {
  array=("$@")

  for ft in "${array[@]}"; do
     echo "♨️  $ft"
    run_all_behavior_test $ft
    # run_all_benchmark $ft
    # echo "👌 all good bro\n"
  done
}

################################################################################

compile_as_lib

echo "Libft Test - PART I"
run_test "${PART_I[@]}"

echo "Libft Test - PART II"
run_test "${PART_II[@]}"

echo "Libft Test - BONUS"
run_test "${BONUS[@]}"

rm -f libft.a
