#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cmath>

#define LARGEVAL (99999999)

using namespace std;

#define DIST(x1, y1, x2, y2) (sqrt(((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2))))

double eval(int n, vector<int> &x, vector<int> &y, vector<int> &seq) {
	double dist = 0;
	int px = 0;
	int py = 0;

	for(vector<int>::iterator it = seq.begin(); it != seq.end(); it++) {
//		double xx = (px - x[*it]) * (px - x[*it]);
//		double yy = (py - y[*it]) * (py - y[*it]);
		//dist += sqrt(xx + yy);	
		dist += DIST(px, py, x[*it], y[*it]);
		px = x[*it];
		py = y[*it];
	}

	return dist;
}


vector<int> opt2swap(vector<int> &seq) {
	int n = seq.size();
	int j = rand() % n;
	int k = rand() % n;
	if (j > k) {
		int tmp = j;
		j = k;
		k = tmp;
	}

	vector<int> newseq;
	for(int i = 0; i < j; i++) {
		newseq.push_back(seq[i]);
	}
	for(int i = k - 1; i >= j; i--) {
		newseq.push_back(seq[i]);
	}

	for(int i = k; i < n; i++) {
		newseq.push_back(seq[i]);
	}
 
	return newseq;
}

vector<int> solution_sa(int n, vector<int> &x, vector<int> &y, vector<int> curseq) {
		
	vector<int> bestseq;
	double besteval = (double)LARGEVAL;
	
	double T = 6000;
	double a1 = 5.0;
	bestseq = curseq;
	
	besteval = eval(n, x, y, bestseq);
	double cureval = besteval;
	while(T > 1e-5) {
		vector<int> newseq = opt2swap(curseq);

		double tmpeval = eval(n, x, y, newseq);
		if(exp((cureval - tmpeval) / (a1 * T)) > (double)(rand() % 10000) / 10000) {
			cureval = tmpeval;
			curseq = newseq;
		} 

		if (cureval < besteval) {
			besteval = cureval;
			bestseq = curseq;
		}
		T *= 0.9999;
	}

	return bestseq;
}

vector<int> solution_nearest(int n, vector<int> &x, vector<int> &y) {
	int px = 0;
	int py = 0;
	vector<int> seq;
	int visited[n];
	for(int i = 0; i < n; i++) {
		visited[i] = 0;			
	}
	for(int i = 0; i < n; i++) {
		double dd = (double)LARGEVAL;
		int nn = -1;
		for(int j = 0; j < n; j++) {
			if(visited[j] == 1) continue;
			double d = DIST(px, py, x[j], y[j]);
			if (d < dd) {
				nn = j;
				dd = d;				
			}
		}
		visited[nn] = 1;
		px = x[nn];
		py = y[nn];
		seq.push_back(nn);
	}
	return seq;
}

int main(int argc, char ** argv) {

	vector<int> x;
	vector<int> y;

	int n;
	cin >> n;
	cout << "Number of nodes " << n << endl;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a;
		cin >> b;
		x.push_back(a);
		y.push_back(b);
//	cout <<a << b << endl;
	}

	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int seedval = atoi(argv[3]);
	cout << "width " << width << " ";
	cout << "height " << height << " ";
	cout << "seed " << seedval << endl;

	vector<int> curseq = solution_nearest(x.size(), x, y);
	double length = eval(n, x, y, curseq);
	cout << "nearestfinal " << curseq.size() << " " << width << " " << height << " " << seedval << " " << length << endl;

//	for(int i = 0; i < n; i++) {
//		curseq[i] = i;
//	}
	srand(seedval);
	curseq = solution_sa(x.size(), x, y, curseq);
	length = eval(n, x, y, curseq);
	cout << "safinal " << curseq.size() << " " << width << " " << height << " " << seedval << " " << length << endl;
	return 0;
}



