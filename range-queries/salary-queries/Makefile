CFLAGS = -Wall -Werror -stdc++=20

OBJS = salary_queries
BINS = query_salary

make_%: %.c
	clang++ $(CFLAGS) -c $^ -o $*.o
