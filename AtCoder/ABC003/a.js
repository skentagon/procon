var stdin = require('fs').readFileSync('/dev/stdin', 'utf8');
console.log((Number(stdin.split('\n')[0]) + 1) * 5000);
