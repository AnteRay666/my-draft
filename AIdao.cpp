#include<bits/stdc++.h>
using namespace std;

struct point {
	int id;
	int x, y;
	point(int id, int x, int y) : id(id), x(x), y(y) {}
};

class TSP {
private:
	const int idNum = 100; // 种群个体数
	const double variProbability = 0.05; // 变异概率
	vector<point> coords; // 各点坐标
	vector<vector<double>> distance; // 各点距离
	vector<vector<int>> route; // 路线种群
	vector<pair<double, int>> fitness; // 各路线的适应度(适应度，种群下标)
	vector<int> bestRoute; // 最优路线
	double minDistance = INT32_MAX; // 最短路径

	vector<point> extraData(const string& path) {
		ifstream fileStream(path);
		int id = 0, x = 0, y = 0;
		vector<point> res;
		while (!fileStream.eof()) {
			string s;
			fileStream >> s;
			id = stoi(s);
			fileStream >> s;
			x = stoi(s);
			fileStream >> s;
			y = stoi(s);
			res.emplace_back(id, x, y);
		}
		fileStream.close();
		return res;
	}
	void initDistance() {
		int n = coords.size();
		distance = vector<vector<double>>(n, vector<double>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				double dis = sqrt(pow(coords[i].x - coords[j].x, 2) + pow(coords[i].y - coords[j].y, 2));
				distance[i][j] = dis;
			}
		}
	}
	void initRoute() {
		vector<int> temp;
		for (int i = 0; i < coords.size(); ++i) {
			temp.emplace_back(i);
		}
		for (int i = 0; i < idNum; ++i) {
			random_shuffle(temp.begin(), temp.end());
			route.emplace_back(temp);
		}
		fitness = vector<pair<double, int>>(idNum); // 初始化适应度大小
	}
	void updateFitness() { // 适应度函数 f = 1/D（D为路线的距离总和）
		for (int i = 0; i < idNum; ++i) {
			double D = 0;
			for (int j = 0; j < route[i].size(); ++j) {
				int xi = 0, yi = 0;
				if (j != route[i].size() - 1) {
					xi = route[i][j], yi = route[i][j + 1];
				}
				else {
					xi = route[i][j], yi = route[i][0];
				}
				D += sqrt(pow(coords[xi].x - coords[yi].x, 2) + pow(coords[xi].y - coords[yi].y, 2));
			}
			if (minDistance > D) {
				minDistance = D;
				bestRoute = route[i];
			}
			fitness[i].first = 1.0 / D;
			fitness[i].second = i;
		}
	}
	void selectAlgorithm() { // 根据适应度带权选择个体
		sort(fitness.begin(), fitness.end(), greater<pair<double, int>>());
		vector<vector<int>> newRoute = route;
		for (int i = 0; i < idNum; ++i) {
			newRoute[i] = route[fitness[i / 2].second];
		}
		route = newRoute;
		random_shuffle(route.begin(), route.end());
	}
	void crossAlgorithm() {
		vector<int> child1;
		vector<int> child2;
		for (int i = 0; i < idNum - 1; i += 2) {
			// route[i] 与 route[i + 1] 交叉
			child1 = route[i];
			child2 = route[i + 1];
			int rVal1 = rand() % route[0].size();
			int rVal2 = rand() % route[0].size();
			int p1 = min(rVal1, rVal2), p2 = max(rVal1, rVal2); // 随机确定左右区间
			int k = p1;
			for (int j = 0; j < route[0].size(); ++j) {
				auto it = find(route[i].begin() + p1, route[i].begin() + p2 + 1, route[i + 1][j]);
				if (it != route[i].begin() + p2 + 1) {
					swap(child2[j], child1[k++]);
				}
			}
			route[i] = child1;
			route[i + 1] = child2;
		}
	}
	void variationAlgorithm() { // 随机交换路线中的两城市顺序
		for (int i = 0; i < idNum * variProbability; ++i) {
			int randInd = rand() % idNum;
			int rVal1 = rand() % route[0].size();
			int rVal2 = rand() % route[0].size();
			swap(route[randInd][rVal1], route[randInd][rVal2]);
		}
	}
public:
	void geneticsAlgorithm(const string& path) {
		coords = extraData(path); // 从文本提取坐标数据
		initDistance(); // 初始化距离矩阵
		initRoute(); // 随机生成初始路线
		for (int i = 0; i < 20000; ++i) {
			updateFitness(); // 计算适应度
			selectAlgorithm(); // 自然选择
			crossAlgorithm(); // 交叉遗传
			variationAlgorithm(); // 随机变异
			if (i % 100 == 0) { // 每 100 次打印当前最优解
				cout << "迭代次数：" << i << "\t" << "当前最短路径：" << minDistance << endl;
			}
		}
	}
	vector<int> getBestRoute() { return bestRoute; }
	double getMinDistance() { return minDistance; }
	vector<point> getCoords() { return coords; }
};

int main() {
	srand((unsigned)time(nullptr));
	TSP tsp;
	tsp.geneticsAlgorithm("C:\\Users\\AnteRay\\Desktop\\lv.txt");
	vector<int> bestRoute = tsp.getBestRoute();
	double minDistance = tsp.getMinDistance();
	cout << "最短路径长度为：" << minDistance << endl;
	cout << "最短路径如下所示：" << endl;
	for (int i = 0; i < bestRoute.size(); ++i) {
		cout << bestRoute[i] << "\t";
		if (i > 0 && (i + 1) % 10 == 0) cout << endl;
	}

	// debug
	cout << "\n---------------------------------------------------" << endl;
	double D = 0.0;
	auto coords = tsp.getCoords();
	for (int j = 0; j < coords.size(); ++j) {
		int xi = 0, yi = 0;
		if (j != coords.size() - 1) {
			xi = bestRoute[j], yi = bestRoute[j + 1];
		}
		else {
			xi = bestRoute[j], yi = bestRoute[0];
		}
		D += sqrt(pow(coords[xi].x - coords[yi].x, 2) + pow(coords[xi].y - coords[yi].y, 2));
	}
	cout << "计算得到 D = " << D << endl;
}
