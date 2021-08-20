private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun is_prefix (s: String, p: String) : Boolean {
  var n = s.length;
  for (i in 0 until n) {
    if (s[i] != p[i]) {
      return false;
    }
  }
  return true;
}

fun check(a : ArrayList<String>, p : String) : Boolean {
  var n = a.size;
  for (i in 0 until 2 * n - 2) {
    val s : String = a.get(i);
    if (s.length == n - 1) {
      continue;
    }
    if (is_prefix(s, p) == false) {
      
    }
  }
}

fun main(args: Array<String>) {
  var n = readInt();
  var a = ArrayList<String>();
  for (i in 0 until 2 * n - 2) {
    var s : String = readLn();
    a.add(s);
  }
  var p1 : String = "";
  var p2 : String = "";
  for (i in 0 until 2 * n - 2) {
    val s : String = a.get(i);
    if (s.length == n - 1) {
      if (p1 == "") {
        p1 = s;
      } else {
        p2 = s;
      }
    }
  }
  
}