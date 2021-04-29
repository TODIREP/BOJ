fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val arr = br.readLine().split(" ").map(String::toInt).toIntArray()
    val found = BooleanArray(2000001) { false }
    fun search(cur: Int, sum: Int) {
        if (cur > 0) found[sum] = true
        if (cur == n) return
        search(cur + 1, sum)
        search(cur + 1, sum + arr[cur])
    }
    search(0, 0)
    fun getResult(): Int {
        found.forEachIndexed { index, value ->
            if (index > 0 && !value) return index
        }
        return 0
    }
    bw.write("${getResult()}")
    bw.close()
}