fun main() {
    val n = readLine()!!.toInt()
    var ans: Long = 0
    for (it in 1..n) ans += n / it * it
    println(ans)
}