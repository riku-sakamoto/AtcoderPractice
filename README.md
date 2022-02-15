# Atcoder 練習帳

Atcoder参加用のコード。C++による実装。

- 反省：[memo.md](./memo.md)
- ツール : [tools.cpp](./tools.cpp)

## 環境設定

gccの[公式Image](https://hub.docker.com/_/gcc)を利用する。

```
docker pull gcc
```

### コンパイル

`test.cpp` をコンパイルする場合，次のように書く．

```bash
docker run -i --rm -v $(pwd):/usr/src/app -w /usr/src/app gcc g++ test.cpp
```

### 実行

`a.out`を実行する場合，以下のように書く．

```bash
docker run -i --rm -v $(pwd):/usr/src/app -w /usr/src/app gcc ./a.out
```

エイリアスとしてそれぞれ設定しておくと便利．
