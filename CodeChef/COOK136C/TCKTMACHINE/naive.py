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
# from typing import *



# def solve(a: int, b: List[int], c: List[List[int]], d: List[List[int]], e: List[List[int]], f: List[int]) -> Tuple[str, str, str, str, List[str], List[str], List[str]]:
def solve(a, b, c, d, e, f):
    pass  # TODO: edit here

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    a = int(next(tokens))
    b = [None for _ in range(a)]
    c = [[None for _ in range(b_i)] for _ in range(a)]
    d = [[None for _ in range(b_i)] for _ in range(a)]
    e = [[None for _ in range(b_i)] for _ in range(a)]
    f = [None for _ in range(a)]
    for i in range(a):
        b[i] = int(next(tokens))
        for j in range(b_i):
            c[i][j] = int(next(tokens))
            d[i][j] = int(next(tokens))
            e[i][j] = int(next(tokens))
        f[i] = int(next(tokens))
    assert next(tokens, None) is None
    o, p, q, r, s, t, u = solve(a, b, c, d, e, f)
    print(o, end=' ')
    print(p, end=' ')
    print(q, end=' ')
    print(r, end=' ')
    for k in range(a):
        print(s[k], t[k], u[k])

if __name__ == '__main__':
    main()
