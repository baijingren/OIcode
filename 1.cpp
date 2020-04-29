void dij()
{
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = hd[u]; i != -1; i = edge[i].nxt)
        {
            int v = edge[i].nxt;
            if (dis[u] + edge[i].w < dis[v])
            {
				secondmin = min;
				dis[v] = dis[u] + edge[i].w;
				q.push(NODE(dis[v], v));
            }
        }
    }
}