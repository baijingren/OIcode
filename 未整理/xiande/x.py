qwe = 100001
siz = [0 for i in range(qwe)]
son = [0 for i in range(qwe)]
tree = [0 for i in range(qwe)]
cnt = [0 for i in range(qwe)]
L = [0 for i in range(qwe)]
id = [0 for i in range(qwe)]
e = [[] for i in range(qwe)]
ans = [0 for i in range(qwe)]
a = [0]
q = [[] for i in range(qwe)]
dfn = 0


def change(x, k):
    while x <= qwe - 1:
        tree[x] += k
        x += (x & (-x))


def ask(x):
    ans = 0
    while x > 0:
        ans += tree[x]
        x -= (x & (-x))
    return ans


def add(x):
    if cnt[a[x]] != 0:
        change(cnt[a[x]], -1)
    cnt[a[x]] += 1
    change(cnt[a[x]], 1)


def dl(x):
    change(cnt[a[x]], -1)
    cnt[a[x]] -= 1
    if cnt[a[x]] != 0:
        change(cnt[a[x]], 1)


def dfs(u, fa):
    global siz, dfn, L
    siz[u] = 1
    dfn += 1
    L[u] = dfn
    id[dfn] = u
    for v in e[u]:
        if v == fa:
            continue
        dfs(v, u)
        siz[u] += siz[v]
        if siz[v] > siz[son[u]]:
            son[u] = v


def dfs2(u, fa, k):
    for v in e[u]:
        if v == fa or v == son[u]:
            continue
        dfs2(v, u, 0)
    if son[u] != 0:
        dfs2(son[u], u, 1)
    for v in e[u]:
        if v == fa or v == son[u]:
            continue
        for i in range(L[v], L[v] + siz[v]):
            add(id[i])
    add(u)
    for j in q[u]:
        ans[j[1]] = ask(qwe - 1) - ask(j[0] - 1)
    if k == 0:
        for i in range(L[u], L[u] + siz[u]):
            dl (id[i])


if __name__ == "__main__":
    a = input().split()
    n = int(a[0])
    m = int(a[1])
    a=[0]
    k=input().split()
    for i in range(1,n+1):
        a.append(int(k[i-1]))
    for i in range(1, n):
        u = input().split()
        v = int(u[1])
        u = int(u[0])
        e[u].append(v)
        e[v].append(u)
    for i in range(1, m + 1):
        k = input().split()
        v = int(k[0])
        k = int(k[1])
        q[v].append([k, i])
    dfs(1, 0)
    dfs2(1, 0, 0)
    for i in range(1, m + 1):
        print(ans[i])
