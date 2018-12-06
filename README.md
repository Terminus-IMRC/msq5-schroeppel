# msq5-schroeppel

This program calculates the number of MSQs (magic squares) of order 5, with the
same algorithm which Richard Schroeppel adopted <a href="#ref-1">[1]</a>.


## How to run

```
$ cc -W -Wall -Wextra -O2 schroeppel.c -o schroeppel
$ ./schroeppel
```


## Result

```
Count (d, x, msq) of A= 0: 732 433548 1091448
Count (d, x, msq) of A= 1: 756 473580 1366179
Count (d, x, msq) of A= 2: 789 526824 1914984
Count (d, x, msq) of A= 3: 804 556524 1958837
Count (d, x, msq) of A= 4: 828 599256 2431806
Count (d, x, msq) of A= 5: 840 625428 2600879
Count (d, x, msq) of A= 6: 858 659628 3016881
Count (d, x, msq) of A= 7: 861 670320 3112161
Count (d, x, msq) of A= 8: 876 699732 3472540
Count (d, x, msq) of A= 9: 876 704268 3344034
Count (d, x, msq) of A=10: 891 733212 3933818
Count (d, x, msq) of A=11: 891 735120 3784618
Count (d, x, msq) of A=12: 906 762660 4769936
sum = 68826306
```

By multiplying the result by 4, you can get the famous result 275305224.


<br /><hr />
<sup id="ref-1">[1]: Michael Beeler (with Assistance from Richard Schroeppel), "Appendix 5: The Order 5 Magic Squares", December 1973
