int n,k,t,sum,ans;
int maxx = -1;
int minn = 999999999;
int a[maxn];
int main()
{
    n = read();
    cin >> k;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        maxx = max(maxn,t);
        minn = min(minn,t);
        a[t]++;//��¼��ǰ�߶ȵĸ��� 
    }
    for(int i=maxx;i>=minn;i--)
    //����ߵ����ö�� 
    {
        if(a[i] == n)//��ǰ���и߶��Ѿ���ͬ 
        {
            if(sum){
                ans++;  break;
            }
        }
        if(sum+a[i] <= k){
            sum += a[i];
        }
        else
        {
            ans++;
            sum = 0;
            if(sum+a[i] <= k){
                sum += a[i];
            }
        }
        a[i-1] += a[i];
        a[i] = 0;
    }
    cout << ans << endl;
    return 0;
}

