// Given a graph represented by an adjacency list with vectors and a
// source, Dijkstra algorithm compute the shortest distance to each
// of the other nodes from source, putting INF if it's not possible to reach them

// Input:
vector<pair<double, int> > adj[MAXN]; // The adjancecy list where the pair stores the weight and the node it goes of that edge
int source; // The node from where you will start the path

// Output:
double distan[MAXN]; // Array where the shortest distance will be stored

// Some other useful variables
#define INF 1e15 // Some constant big enough to represent infinity
bool visited[MAXN];
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;

// Initialization
void init() {
	for (int i = 0; i < MAXN; i++)
		adj[i].clear();
	fill(vis, vis + MAXN, false);
	fill(distan, distan + MAXN, INF);
}

// The algorithm
void dijkstra() {	
	while (!q.empty()) {
			pair<double, int> curr = q.top(); q.pop();
			if (vis[curr.second]) continue;
			vis[curr.second] = true;

			distan[curr.second] = curr.first;

			for (auto e : adj[curr.second]) {
				if (!vis[e.second])
					q.push(make_pair(distan[curr.second] + e.first, e.second));
			}
		}
}

// How you use it

int main() {
	q.push(make_pair(0.0, source));
	dijkstra();
	cout << "The shortest path from source to a node v is " << distan[v] << endl;
}
