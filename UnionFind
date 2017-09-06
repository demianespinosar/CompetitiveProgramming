// also known as Disjoint-Set Data Structure
// https://en.wikipedia.org/wiki/Disjoint-set_data_structure

int p[maxn];

void init(){
	for (int i = 0; i < maxn; i++)
		p[i] = i;
}

int id(int x){
	if (x == p[x]) return x
	return p[x] = id(p[x]);
}

int join(int x, int y){
	p[id(x)] = id(y);
}
