/*
在选举中，第 i 张票是在时间为 times[i] 时投给 persons[i] 的。

现在，我们想要实现下面的查询函数： TopVotedCandidate.q(int t) 将返回在 t 时刻主导选举的候选人的编号。

在 t 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。

示例：

输入：["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
输出：[null,0,1,1,0,0,1]
解释：
时间为 3，票数分布情况是 [0]，编号为 0 的候选人领先。
时间为 12，票数分布情况是 [0,1,1]，编号为 1 的候选人领先。
时间为 25，票数分布情况是 [0,1,1,0,0,1]，编号为 1 的候选人领先（因为最近的投票结果是平局）。
在时间 15、24 和 8 处继续执行 3 个查询。
 

提示：

1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times 是严格递增的数组，所有元素都在 [0, 10^9] 范围中。
每个测试用例最多调用 10000 次 TopVotedCandidate.q。
TopVotedCandidate.q(int t) 被调用时总是满足 t >= times[0]。
*/

class TopVotedCandidate {
public:
    int* lstPersons = NULL, *lstTimeLeader = NULL;
    vector<int> times;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        this->times = times;
        this->lstPersons = new int[times.size()];                                   // 所有备选人的票数统计表
        this->lstTimeLeader = new int[times.size()];
        for (int i = 0; i < times.size(); ++i) {
            this->lstPersons[i] = 0;
            this->lstTimeLeader[i] = 0;
        }
        
        for (int i = 0; i < times.size(); ++i) {
            this->lstPersons[persons[i]]++;                                               // times[i]时间投了persons[i]此人一票
            if (i == 0) {                                                           // 如果时间为第一次投票时间
                this->lstTimeLeader[i] = persons[i];                                      // 那么在第一次投票时间被投的人为leader
            } else if (persons[i] != this->lstTimeLeader[i - 1]) {
                // 前提：当前被投票这个人如果跟上一个时间的leader相同，则不变
                // 否则就拿当前被投票的这个人的票数跟上一个时间的leader的票数对比，谁多谁是leader
                if (this->lstPersons[persons[i]] >= this->lstPersons[this->lstTimeLeader[i - 1]]) {
                    this->lstTimeLeader[i] = persons[i];
                } else {
                    this->lstTimeLeader[i] = this->lstTimeLeader[i - 1];
                }
            } else {
                this->lstTimeLeader[i] = persons[i];
            }
        }
        cout << "最终票数表\t:\t";
        for (int i = 0; i < times.size(); ++i) {
            cout << this->lstPersons[i] << "\t";
        }
        cout << endl;
        
        cout << "各个投票的时间\t:\t";
        for (int i = 0; i < times.size(); ++i) {
            cout << times[i] << "\t";
        }
        cout << endl;
        
        cout << "各个投票时间的leader\t:\t";
        for (int i = 0; i < times.size(); ++i) {
            cout << this->lstTimeLeader[i] << "\t";
        }
        cout << endl;
    }
    
    int q(int t) {
        // 返回在t时刻领先的人的编号
        for (int i = 1; i < this->times.size(); ++i) {
            if (t < times[i]) {
                return this->lstTimeLeader[i - 1];
            } else if (t == times[i]) {
                return this->lstTimeLeader[i];
            }
        }
        return this->lstTimeLeader[this->times.size() - 1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */