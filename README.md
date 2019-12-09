## コムソートのパラメータ1.3が適当であるかをチェックする

```
$ g++ comb_sort.cpp
$ ./a.out
div[1.1] : 56.99ms
div[1.2] : 20.884ms
div[1.3] : 19.665ms
div[1.4] : 875.03ms
div[1.5] : 3113.56ms
div[1.6] : 5381.77ms
...
```

## コムソートを他のソートと比べる

```
$ g++ compare_sort.cpp
$ ./a.out
isSorted(): 1
./a.out  0.02s user 0.00s system 99% cpu 0.023 total
```