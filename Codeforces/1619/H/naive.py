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



# def solve(a: str, b: str, c: str, d: str, e: List[str], f: List[str], g: List[str]) -> Any:
def solve(a, b, c, d, e, f, g):
    pass  # TODO: edit here

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    a = next(tokens)
    b = next(tokens)
    e = [None for _ in range(b)]
    f = [None for _ in range(b)]
    g = [None for _ in range(b)]
    c = next(tokens)
    d = next(tokens)
    for i in range(b):
        e[i] = next(tokens)
        f[i] = next(tokens)
        g[i] = next(tokens)
    assert next(tokens, None) is None
    ans = solve(a, b, c, d, e, f, g)
    print(ans)  # TODO: edit here

if __name__ == '__main__':
    main()
