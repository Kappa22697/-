# 探索アルゴリズム(cpp)

基本情報B問題にあるようなもの、

---

## 1. 配列探索 (Array_Search.cpp)

配列に対する基本的な探索アルゴリズムの実装です。

### 実装されているアルゴリズム

#### 1.1 線形探索 (Linear Search)
- **時間計算量**: O(n)
- **空間計算量**: O(1)
- **特徴**:
  - 配列を先頭から順番に探索
  - ソートされていない配列でも使用可能
  - 実装が最もシンプル

```cpp
int linearSearch(const vector<int>& arr, int target)
```

**動作例**:
```
配列: [64, 34, 25, 12, 22, 11, 90]
探索値: 22
結果: インデックス 4 で発見
```

#### 1.2 二分探索 (Binary Search)
- **時間計算量**: O(log n)
- **空間計算量**: O(1)
- **特徴**:
  - 中央値と比較して探索範囲を半分ずつ狭める
  - **配列が事前にソートされている必要がある**
  - 大規模なデータに対して非常に効率的

```cpp
int binarySearch(const vector<int>& arr, int target)
```

**動作例**:
```
ソート済み配列: [11, 12, 22, 25, 34, 64, 90]
探索値: 25
手順:
  1. 中央 = 25 → 発見！
結果: インデックス 3
```

#### 1.3 二分探索 (再帰版)
- 二分探索の再帰実装
- 計算量は反復版と同じだが、関数呼び出しのオーバーヘッドがある

```cpp
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right)
```

### コンパイルと実行

```bash
g++ -o Array_Search Array_Search.cpp
./Array_Search
```

### 実行結果例

```
=== Linear Search Test ===
Array: 64 34 25 12 22 11 90

Value 22 found at index 4
Value 100 not found

=== Binary Search Test ===
Sorted Array: 11 12 22 25 34 64 90

Value 25 found at index 3
Value 50 not found

=== Binary Search (Recursive) Test ===
Value 64 found at index 5
```

---

## 2. 木構造探索 (kikouzou_search.cpp)

二分探索木(Binary Search Tree)と木構造の探索アルゴリズムの実装です。

### 二分探索木 (BST) の特徴

- **左の子ノード < 親ノード < 右の子ノード**
- この性質により、効率的な探索が可能

### 木の構造例

```
        50
       /  \
     30    70
    / \    / \
  20  40  60  80
  / \  /   \
10 25 35   65
```

### 実装されている機能

#### 2.1 値の挿入 (Insert)
- **時間計算量**: 平均 O(log n)、最悪 O(n)
- 二分探索木のルールに従って値を挿入

```cpp
void insert(int value)
```

#### 2.2 値の探索 (Search)
- **時間計算量**: 平均 O(log n)、最悪 O(n)
- 反復版と再帰版の2つを実装

```cpp
bool search(int value)              // 反復版
bool searchRecursive(int value)     // 再帰版
```

#### 2.3 深さ優先探索 (DFS: Depth-First Search)

##### 前順巡回 (Pre-order Traversal)
- **訪問順序**: ルート → 左 → 右
- **用途**: 木の構造をコピーする時

```cpp
void preOrder()
```

**結果**: `50 30 20 10 25 40 35 70 60 65 80`

##### 中順巡回 (In-order Traversal)
- **訪問順序**: 左 → ルート → 右
- **重要**: BSTの場合、**ソート済みの順序**で出力される

```cpp
void inOrder()
```

**結果**: `10 20 25 30 35 40 50 60 65 70 80` ← ソート済み！

##### 後順巡回 (Post-order Traversal)
- **訪問順序**: 左 → 右 → ルート
- **用途**: 木を削除する時（子から先に削除）

```cpp
void postOrder()
```

**結果**: `10 25 20 35 40 30 65 60 80 70 50`

#### 2.4 幅優先探索 (BFS: Breadth-First Search)

- **訪問順序**: レベルごとに左から右へ
- **実装**: キュー(queue)を使用
- **用途**: 最短経路探索、レベル単位の処理

```cpp
void levelOrder()
```

**結果**: `50 30 70 20 40 60 80 10 25 35 65`

```
レベル0: 50
レベル1: 30, 70
レベル2: 20, 40, 60, 80
レベル3: 10, 25, 35, 65
```

#### 2.5 その他の機能

```cpp
int getHeight()      // 木の高さを取得
int countNodes()     // ノード数をカウント
```

### コンパイルと実行

```bash
g++ -o kikouzou_search kikouzou_search.cpp
./kikouzou_search
```

### 実行結果例

```
=== Building Binary Search Tree ===
Inserting values: 50 30 70 20 40 60 80 10 25 35 65

Tree height: 4
Total nodes: 11

=== Tree Traversal Methods ===
Pre-order (Root -> Left -> Right): 50 30 20 10 25 40 35 70 60 65 80
In-order (Left -> Root -> Right): 10 20 25 30 35 40 50 60 65 70 80
Post-order (Left -> Right -> Root): 10 25 20 35 40 30 65 60 80 70 50
Level-order (BFS): 50 30 70 20 40 60 80 10 25 35 65

=== Search Test ===
Value 40 found in tree (iterative)
Value 40 found in tree (recursive)

Value 65 found in tree (iterative)
Value 65 found in tree (recursive)

Value 100 not found in tree (iterative)
Value 100 not found in tree (recursive)

Value 10 found in tree (iterative)
Value 10 found in tree (recursive)
```

---

## 木の形状について

### 重要なポイント

木の形状は**挿入する値の順序**によって決まります。

#### バランスの取れた木（良い例）
```cpp
挿入順序: {50, 30, 70, 20, 40, 60, 80}
高さ: 3
```

```
      50
     /  \
   30    70
  / \    / \
 20 40  60 80
```

#### 偏った木（悪い例）
```cpp
挿入順序: {10, 20, 30, 40, 50, 60, 70}
高さ: 7
```

```
10
 \
  20
   \
    30
     \
      40
       \
        50
         \
          60
           \
            70
```

この場合、探索の時間計算量が O(n) になり、線形探索と変わらなくなってしまいます。

### 解決方法

偏った木を防ぐために、以下のような自己平衡木を使用します:
- **AVL木**: 各ノードで左右の部分木の高さの差を1以内に保つ
- **赤黒木**: 色の制約により、高さのバランスを保つ
- **B木**: データベースやファイルシステムで使用される

---

## アルゴリズムの比較

### 配列探索

| アルゴリズム | 時間計算量 | 空間計算量 | 条件 | 利点 | 欠点 |
|------------|----------|----------|-----|------|------|
| 線形探索 | O(n) | O(1) | なし | シンプル、ソート不要 | 遅い |
| 二分探索 | O(log n) | O(1) | ソート済み | 高速 | ソートが必要 |

### 木構造の探索

| 巡回方法 | 用途 | 特徴 |
|---------|-----|------|
| 前順 (Pre-order) | 木のコピー | ルートを最初に訪問 |
| 中順 (In-order) | ソート済み出力 | BSTでソート順 |
| 後順 (Post-order) | 木の削除 | 子から先に処理 |
| レベル順 (BFS) | 最短経路 | 階層ごとに処理 |

---

## まとめ

- **配列探索**: シンプルで基本的なアルゴリズム
  - 線形探索: すべての配列で使用可能
  - 二分探索: ソート済み配列で高速

- **木構造探索**: 階層的なデータに対して効率的
  - BST: 挿入・探索・削除が平均 O(log n)
  - DFS: 深さ方向に探索（スタック／再帰）
  - BFS: 幅方向に探索（キュー）

どちらも基本的で重要なアルゴリズムです！
