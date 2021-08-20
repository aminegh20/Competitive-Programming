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
    var (n, k) = readInts();
    var s : String = "";
    var c : Char = 'a';
    var cnt = 0;
    while (s.length < n) {
      s += c;
      cnt += 1;
      if (cnt == k) {
        cnt = 0;
        c = 'a';
      } else {
        c += 1;
      }
    }
    println(s);
  }
}