private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
  
fun main(args: Array<String>) {
  var tt = readInt();
  for (qq in 0 until tt) {
    var (a : Long, b : Long, k : Long) = readLongs();
    var ans : Long = ((k + 1)/ 2) * a - ((k + 1)/ 2) * b;
    if (k % 2L == 1L) {
      ans += b;
    }
    println(ans);
  }
}