//7-3 账户安全预警
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int n, k, p;
unordered_map<string, unordered_map<string, int>> mp;

struct IPS
{
	string ip;
	int cnt;
	
	bool operator < (const IPS &ips) const
	{
		if(cnt != ips.cnt)
			return cnt > ips.cnt;
		return ip < ips.ip; 
	} 
};

struct Record
{
	string email;
	vector<IPS> ips;
	int cnt;
	
	bool operator < (const Record &r) const
	{
		if(ips.size() != r.ips.size())
			return ips.size() > r.ips.size();
		return email < r.email;
	}
};

vector<Record> records;
vector<Record> res;

int main()
{
	scanf("%d %d %d", &n, &k, &p);
	for(int i = 0; i < n ; i++)
	{
		char email[56], ip[18];
		scanf("%s %s", email, ip);
		mp[email][ip]++;
	}
	
	for(auto &m : mp)
	{
		int cnt = 0;
		vector<IPS> ips;
		for(auto &v : m.second)
		{
			cnt += v.second;
			ips.push_back({v.first, v.second});
		}
		
		sort(ips.begin(), ips.end());
		records.push_back({m.first, ips, cnt});
	}
	
	for(Record &r : records)
	{
		if(r.ips.size() <= k || r.cnt <= p)
			continue;
		res.push_back(r);
	}
	
	if(res.size())
	{
		sort(res.begin(), res.end());
		for(Record &r : res)
		{
			cout << r.email << endl;
			for(IPS &ips : r.ips)
			{
				cout << ips.ip << ' ' << ips.cnt << endl;
			}	
		}
	}
	else
	{
		sort(records.begin(), records.end());
		for(int i = 0; i < records.size() && records[i].ips.size() == records[0].ips.size(); i++)
		{
			Record r = records[i];
			cout << r.email << endl;
			for(IPS &ips : r.ips)
			{
				cout << ips.ip << ' ' << ips.cnt << endl;
			}	
		}
	}
	return 0;
}
