private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
  
fun main(args: Array<String>) {
  var n = readInt();
  var a = readLongs();
  var b = ArrayList<Int>();
  for (i in 0 until n) {
    b.add(i);
  }
  b.sortWith(
   Comparator<Int> { i, j -> 
      when {
        a[i] > a[j] -> 1;
        a[i] < a[j] -> -1;
        else -> 0;
      }
    } 
  );
  var sum : Long = 0L;
  for (i in 0 until n - 1) {
    sum += a[b[i]];
  }
  var ans = ArrayList<Int>();
  for (i in 0 until n - 1) {
    if (sum - a[b[i]] == a[b[n - 1]]) {
      ans.add(b[i] + 1);
    }
  }
  sum -= a[b[n - 2]];
  if (sum == a[b[n - 2]]) {
    ans.add(b[n - 1] + 1);
  }
  println(ans.size);
  for (v in ans) {
    print("$v ");
  }
  println();
}