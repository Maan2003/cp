Traceback (most recent call last):
  File "/home/manmeet/.local/lib/python3.10/site-packages/onlinejudge_template/generator/hook.py", line 28, in _execute_hook
    return subprocess.check_output(data['hook'], input=rendered, stderr=sys.stderr)
  File "/usr/lib/python3.10/subprocess.py", line 420, in check_output
    return run(*popenargs, stdout=PIPE, timeout=timeout, check=True,
  File "/usr/lib/python3.10/subprocess.py", line 524, in run
    raise CalledProcessError(retcode, process.args,
subprocess.CalledProcessError: Command '['yapf', '--style', '{BASED_ON_STYLE: google, COLUMN_LIMIT: 9999}']' returned non-zero exit status 1.


Generated code (before processed by the filter):
#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    a = random.randint(1, 1000)  # TODO: edit here
    b = [None for _ in range(a)]
    c = [[None for _ in range(b_i)] for _ in range(a)]
    for i in range(a):
        b[i] = random.randint(1, 10 ** 9)  # TODO: edit here
        for j in range(b_i):
            c[i][j] = random.randint(1, 10 ** 9)  # TODO: edit here
    print(a)
    for i in range(a):
        print(b[i])
        print(*[c[i][j] for j in range(b_i)])

if __name__ == "__main__":
    main()
