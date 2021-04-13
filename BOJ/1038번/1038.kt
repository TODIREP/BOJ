fun main() {
    val n = readLine()!!.toInt()
    val number = mutableListOf<String>()
    fun search(cnt: Int, first: Int, cur: String) {
        if ((cnt <= 10) and (cnt > 0)) {
            number.add(cur)
        }
        if (cnt == 10) return
        for (next in 0 until first) {
            search(cnt + 1, next, cur.plus(next.toString()))
        }
    }
    search(0, 10, "")
    number.sortBy { it.length }
    if (n >= number.size) print(-1)
    else print(number[n])
}