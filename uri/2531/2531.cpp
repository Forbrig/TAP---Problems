#include <cstdio>

void segtree_build (int arr[], int tree[], int node, int left, int right) {
  if (left == right) {
    tree[node] = arr[left];
  } else {
    int mid = (left + right) / 2;
    segtree_build(arr, tree, 2*node, left, mid);
    segtree_build(arr, tree, 2*node+1, mid+1, right);
    tree[node] = tree[2*node] + tree[2*node+1];

    // if (tree[2*node] > tree[2*node+1]){
    //   tree[node] = tree[2*node];
    // } else {
    //   tree[node] = tree[2*node+1];
    // }
    // if (tree[node] < 0) {
    //   tree[node] = tree[node] * -1;
    // }
  }
  printf("%d ", tree[node]);
  return;
}

int main ( ) {
  int n, l, r, q, op;
  scanf("%d", &n);
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
      //for (int i = 0; i < n; i++) {
        segtree_build(p, tree, i, 0, n-1);
        //printf("%d ", p[i]);
      //}
      //printf("\n");

      // for (int j = 0; j < 2*n-1; j++) {
      //   printf("%d ", tree[j]);
      // }
      // printf("\n");
    }
  }
  return 0;
}
