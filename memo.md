# 学習メモ

## 20200823

- deque

## 20200829

- UnionFind

```c++
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

};
```

- エラトステネスの篩
  - 1. 2からnまでの整数を並べる
  - 2. 生き残っていて、未使用の整数をpとおき、p以外のpの倍数を消す
  - 3. pが√nを超えたら終了

## 20200913

- 動的計画＝＞部分和

- マンハッタン問題＝＞４５度回転

## 20200919

要復習「E問題」

‐ 配るDP
- あまりは繰り返す。鳩ノ巣原理で余りの分だけ、-1で初期化したvectorを用意してそこにインデックスを入れていく。

## 20210808

- C問題（座標圧縮）

[3, 4, 5, 7, 6, 3] => [0, 1, 2, 4, 3, 0]

```cpp
// 重複の削除
// 1.ソート
// 2.uniqueで隣接する重複削除 => vectorの長さを変更しないため，末尾にゴミが残る
// 3.uniqueはごみの手前のポインタを返すので，そこから最後までeraseで削除
sort(ALL(list));
erase(unique(ALL(list)), list.end())


// インデックスの検索
// ソート済み範囲に対して、任意の値を二分探索で見つける
int target = 2;
int i = lower_bound(ALL(list), target) - list.begin();

```


- D問題（オイラーツアー）

深さ優先探索

## 20210828

- D問題

シミュレーションは重複部をメモ化できないか考える

- E問題

大きな配列でソートできない時は二分探索で考える
「ｍ以上の数がＫ個以下存在するか」ｍについて単調


## 20210904

- D問題

setの使い方

st.lower_boundはO(logN)

prev(it)で一つ前のイテレータをとれる

- E問題

vectorでは削除はO（N)，ソートはO(NlogN)かかるのでqueueを使うという感覚

## 20210911

- C
リファクタリングを実施する心がけ

- D
pairのvectorをソートする
binary_search


## 20211009

- E

dfsによる木上の探索＋DP
Cの配列は初期化忘れが多い。vectorを使う
インデックスのオフセット

## 20211017

- D

トポロジカルソート
入次数（その番号に入ってくる数）に注目して，リストにする。
入次数＝０がフリー

## 20211204

- D

pair のソートについて

比較関数について
（a, b）の順番できた時，aが前に来るときにtrueを返す
＝＞(a, b)の順番がどういう関係をもっているかを記載すればいい

```cpp
using P = pair<LL, LL>;
sort(ALL(vec), [](P& a, P& b){return a.second < b.second})
```


## 20211218

- C
FORの一回忘れに注意

## 20211225

- D

まずはN＾２を作ってから，最適化を考える
mapは存在しないキーの時，０を返してくれる
