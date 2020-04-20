//判断是否为单值二叉树
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return l > r ? l + 1 : r + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	struct TreeNode* p = root->left;
	struct TreeNode* q = root->right;
	int ret = abs(maxDepth(p) - maxDepth(q));
	return ret <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
bool func(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val&&func(p->left, q->right) && func(p->right, q->left);

}

bool isSymmetric(struct TreeNode* root) {
	return func(root, root);
}

int maxDepth(struct TreeNode* root) {
	/*if (root == NULL)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return l > r ? l + 1 : r + 1;*/
	return !root ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


