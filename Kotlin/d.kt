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
  var a = readInts().sorted();
  var ans = 0;
  for (i in 0 until n - 1 step 2) {
    ans += a[i + 1] - a[i];
  }
  println(ans);
}