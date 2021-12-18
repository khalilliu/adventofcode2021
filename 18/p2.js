
const fs = require('fs');
const { get } = require('http');

function getInput(filename) {
  var arr = fs.readFileSync(filename).toString().split('\n').filter(Boolean)
  console.log(arr);
  return arr;
}


let nodes = [], temp = [], idx = -1;

function find(root, depth) {
  if (root == -1) return -1;
  if (depth == 0) {
    if (!nodes[root].is_leaf) return root;
    else return -1;
  }
  let node = find(nodes[root].left, depth - 1);
  if (node != -1) return node;
  return find(nodes[root].right, depth - 1);
}

function add_left(node, val) {
  //   console.log(nodes[node])
  if (!nodes[node].is_left) {
    let p = nodes[node].parent;
    if (nodes[nodes[p].left].is_leaf) nodes[nodes[p].left].val += val;
    else {
      p = nodes[nodes[p].left].right;
      while (!nodes[p].is_leaf) p = nodes[p].right;
      nodes[p].val += val;
    }
  } else {
    // node is left child
    let p = nodes[node].parent;
    while (p != -1 && nodes[p].is_left) p = nodes[p].parent;
    if (p == -1 || nodes[p].parent == -1) return;
    add_left(p, val);
  }
}

function add_right(node, val) {
  if (nodes[node].is_left) {
    let p = nodes[node].parent;
    if (nodes[nodes[p].right].is_leaf) nodes[nodes[p].right].val += val;
    else {
      p = nodes[nodes[p].right].left;
      while (!nodes[p].is_leaf) p = nodes[p].left;
      nodes[p].val += val;
    }
  } else {
    let p = nodes[node].parent;
    while (p != -1 && !nodes[p].is_left) p = nodes[p].parent;
    if (p == -1 || nodes[p].parent == -1) return;
    add_right(p, val);
  }
}

function explode(root) {
  let node = find(root, 4)
  if (node == -1) return false;
  //   console.log(nodes[nodes[node].left], nodes[nodes[node].right]);
  //   return;
  add_left(node, nodes[nodes[node].left].val);
  add_right(node, nodes[nodes[node].right].val);
  nodes[node].left = -1, nodes[node].right = -1;
  nodes[node].val = 0, nodes[node].is_leaf = true;
  return true;
}

function split(root) {
  if (nodes[root].is_leaf) {
    if (nodes[root].val >= 10) {
      let t = nodes[root].val;
      let left = { left: -1, right: -1, parent: root, val: Math.trunc(t / 2), is_leaf: true, is_left: true };
      let right = { left: -1, right: -1, parent: root, val: Math.trunc((t + 1) / 2), is_leaf: true, is_left: false };
      nodes.push(left), idx++;
      nodes[root].left = idx;
      nodes.push(right), idx++;
      nodes[root].right = idx;
      nodes[root].is_leaf = false;
      return true;
    }
    return false;
  }

  let has_change = split(nodes[root].left);
  if (has_change) return true;
  return split(nodes[root].right);
}

function clear(root) {
  while (true) {
    let has_change = explode(root)
    //         if(has_change) console.log(stringify(root));
    if (has_change) continue
    has_change = split(root)
    //         if(has_change) console.log(stringify(root));
    if (!has_change) break;
  }
}

function add(a, b) {
  let c = { left: a, right: b, parent: -1, val: 0, is_leaf: false, is_left: false };
  nodes.push(c), idx++;
  root = idx;
  nodes[a].parent = nodes[b].parent = idx;
  nodes[a].is_left = true, nodes[b].is_left = false;
  clear(idx)
  return root;
}

function magnitude(root) {
  if (nodes[root].is_leaf) {
    return nodes[root].val
  }
  return 3 * magnitude(nodes[root].left) + 2 * magnitude(nodes[root].right)
}

function parse(s) {
  let stk = []
  let depth = 0;
  for (let i = 0; i < s.length; i++) {
    if (s[i] == ']') {
      let r = stk.pop();
      let l = stk.pop();
      let cur = { left: l, right: r, parent: -1, val: 0, is_leaf: false };
      nodes.push(cur); idx++;
      nodes[r].parent = idx, nodes[l].parent = idx;
      nodes[l].is_left = true, nodes[r].is_left = false;
      stk.push(idx);
    } else if (s[i] == '[') { depth++; }
    else if (s[i] >= '0' && s[i] <= '9') {
      let cur = { left: -1, right: -1, parent: -1, val: Number(s[i]), is_leaf: true };
      nodes.push(cur); idx++;
      stk.push(idx);
    }
  }
  return stk.pop();
}

function stringify(root) {
  if (nodes[root].is_leaf) return nodes[root].val + '';
  return `[${stringify(nodes[root].left)},${stringify(nodes[root].right)}]`;
};

function get_val(a, b) {
  return magnitude(add(a, b));
}

function main() {
  let input = getInput('./input')
  let ps = input.map(parse);
  let ans = 0;
  temp = nodes.map(node => (Object.assign({}, node)))
  for (let i = 0; i < ps.length; i++) {
    for (let j = 0; j < ps.length; j++) {
      nodes = temp.map(node => (Object.assign({}, node))), idx = nodes.length - 1
      if (i == j) continue;
      ans = Math.max(ans, get_val(ps[i], ps[j]));
    }
  }
  console.log(ans)
}

main()