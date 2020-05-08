Usage: (seeds are either 1 or 2)
```bash
#On Minix:
make test-basic
rm part_output*.txt
echo <seed> | ./test-basic
```

Czekamy aż się skończy i `ps ax | grep test-basic` nic nie wypisze poza samym sobą (czyli tam coś `..... grep test-basic`.
Bo mogłoby jeszcze wypisywać jakieś `./test-basic` gdyby nie wszystkie potomki skończyły.

It may take some minutes to finish on Minix.

```bash
#On Minix:
cat part_output*.txt >output.txt
```

download output.txt

```bash
#On Host:
./change.py output.txt >myRes<seed>
diff res<seed> myRes<seed>
```
