#include <iostream>
#include <vector>
#include <stack>
#include <string>


using namespace std;
class Log {
public:
	int id;
	bool isStart;
	int time;

	Log(const string& content) {
		size_t pos1 = content.find(":");
		size_t pos2 = content.find(":", pos1 + 1);

		id = stoi(content.substr(0, pos1));
		isStart = content.substr(pos1 + 1, pos2 - pos1 - 1) == "start";
		time = stoi(content.substr(pos2 + 1));
	}
};

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		stack<Log> logsStack;
		vector<int> result(n, 0);

		for (const string& content : logs) {
			Log log(content);

			if (log.isStart) {
				logsStack.push(log);
			}
			else {
				Log top = logsStack.top();
				logsStack.pop();
				result[top.id] += log.time - top.time + 1;

				if (!logsStack.empty()) {
					result[logsStack.top().id] -= log.time - top.time + 1;
				}
			}
		}
		return result;
	}
};



vector<int> exclusiveTime(int n, vector<string>& logs) {
	pair<int, string> p;
	stack<pair<int, int>> s;
	vector<int> ans(n);
	int lastPop = 0;

	for (int i = 0; i < logs.size(); i++)
	{
		int id = 0;
		int curTimeStamp = 0;
		int j = 0;

		while (isdigit(logs[i][j])) {
			id = id * 10 + (logs[i][j] - '0');
			j++;
		}
		if (logs[i][j] == ':') j++;

		//----

		if (logs[i][j] == 's') {
			j += 6; //"start" has a length of (5) and + 1 to stand at the next

			while (j < logs[i].size()) {
				curTimeStamp = curTimeStamp * 10 + (logs[i][j] - '0');
				j++;
			}

			if (!s.empty() && lastPop == 0) {
				ans[s.top().first] += curTimeStamp;
			}
			else if(!s.empty() && lastPop != 0){
				ans[s.top().first] += curTimeStamp - lastPop - 1;
			}
			
			s.push(make_pair(id, curTimeStamp));
			lastPop = 0;
		}
		if (logs[i][j] == 'e') {
			j += 4;

			while (isdigit(logs[i][j])) {
				curTimeStamp = curTimeStamp * 10 + (logs[i][j] - '0');
				j++;
			}

			ans[s.top().first] += lastPop == 0 ? curTimeStamp - s.top().second + 1 : curTimeStamp - lastPop;
			lastPop = curTimeStamp;

			s.pop();
		}
	}

	//cuando llegamos a un putno donde una funcion se ejecuto antes de otra, y al final se cierra
	//hay una falla, donde no podemos calcular bien el timestap 
	return ans;

}

int main()
{

	vector<string> v = { "0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7" };
	exclusiveTime(1, v);
}


//if (lastPop != 0) {
//	ans[s.top().first] += curTimeStamp - lastPop;
//}
//else {
//	ans[s.top().first] += curTimeStamp - s.top().second + 1;
//}

