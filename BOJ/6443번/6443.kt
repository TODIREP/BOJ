fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val n = readLine().toInt()
    val check = IntArray(26) { 0 }
    lateinit var result: CharArray
    var length = 0
    fun search(cnt: Int) {
        if (cnt == length) {
            val ans = StringBuilder()
            for (it in 0 until length) ans.append(result[it])
            bw.write(ans.toString() + "\n")
            return
        }
        for (it in 0 until 26) {
            if (check[it] == 0) continue
            check[it]--
            result[cnt] = it.toChar() + 'a'.toInt()
            search(cnt + 1)
            check[it]++
        }
    }
    for (it in 0 until n) {
        val word = readLine()
        length = word.length
        result = CharArray(length)
        for (index in 0 until length) check[word[index] - 'a']++
        search(0)
        for (index in 0 until length) check[word[index] - 'a']--
    }
    bw.close()
}