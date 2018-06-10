#include <cstdio>

// op = 0: smallest value
// op = 1: biggest value
int segtree_build (int arr[], int tree[], int node, int left, int right, int op) {
  if (left == right) {
    tree[node] = arr[left];
  } else {
    int mid = (left + right) / 2;
    //printf("\nmid %d\n", mid);
    segtree_build(arr, tree, 2*node, left, mid, op);
    //printf("seg esq\n");
    segtree_build(arr, tree, 2*node+1, mid+1, right, op);
    //printf("seg dir\n");
    if (op == 0) {
      if (tree[2*node] < tree[2*node+1]){
        tree[node] = tree[2*node];
      } else {
        tree[node] = tree[2*node+1];
      }
    } else if (op == 1) {
        if (tree[2*node] > tree[2*node+1]){
          tree[node] = tree[2*node];
        } else {
          tree[node] = tree[2*node+1];
        }
    }
  }
  //this return the root
  printf("%d ", tree[node]);
  return tree[node];
}

int main ( ) {
  int n, l, r, q, op;
    //scanf("%d", &n);
  while (~scanf("%d", &n) and n) {
    int p[n]; //initial array, shop values

    //Since the constructed tree is always a full binary tree with n leaves, there will be n-1 internal nodes. So total number of nodes will be 2*n – 1.
    int tree[2*n-1];

    for (int i = 0; i < n; i++){
      scanf("%d", &p[i]);
    }
    scanf("%d", &q);

    // op = 1: change values on store n to value m
    // op = 2: query from shop n to shop m
    for (int i = 0; i < q; i++) {
      scanf("%d %d %d", &op, &l, &r);
      if (op == 1) {
        p[l-1] = r;
      } else if (op == 2) {
        int min = segtree_build(p, tree, i, l-1, r-1, 0);
        printf("min %d\n", min);
        int max = segtree_build(p, tree, i, l-1, r-1, 1);
        printf("max %d\n", max);
        printf("%d\n", max - min);
      }
    }
  }
  return 0;
}
