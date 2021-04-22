fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, k) = br.readLine().split(" ").map(String::toInt)
    val words = mutableListOf<String>()
    val using = BooleanArray(26) { false }
    "antic".forEach { using[it - 'a'] = true }
    repeat(n) { words.add(br.readLine()) }
    var answer = 0
    fun search(cnt: Int, cur: Int) {
        if (cnt == k - 5) {
            var count = 0
            repeat(n) {
                var valid = true
                words[it].forEach { word -> if (!using[word - 'a']) valid = false }
                if (valid) count++
            }
            answer = answer.coerceAtLeast(count)
            return
        }
        for (index in cur until 26) {
            if (using[index]) continue
            using[index] = true
            search(cnt + 1, index + 1)
            using[index] = false
        }
    }
    if (k - 5 >= 0) search(0, 0)
    bw.write("$answer")
    bw.close()
}