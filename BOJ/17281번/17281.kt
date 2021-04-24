fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val arr = Array(n) { IntArray(9) }
    repeat(n) { arr[it] = br.readLine().split(" ").map(String::toInt).toIntArray() }
    val check = BooleanArray(9) { false }
    val order = IntArray(9) { -1 }
    order[3] = 0
    check[0] = true
    var answer = 0
    fun play() {
        var score = 0
        val base = IntArray(3) { 0 }
        var start = 0
        var out = 0
        repeat(n) { cur ->
            while (out < 3) {
                when (arr[cur][order[start]]) {
                    0 -> out++
                    1 -> {
                        score += base[2]
                        for (index in 2 downTo 1) { base[index] = base[index - 1] }
                        base[0] = 1
                    }
                    2 -> {
                        score += base[2] + base[1]
                        base[2] = base[0]
                        base[1] = 1
                        base[0] = 0
                    }
                    3 -> {
                        score += base.sum()
                        repeat(3) { index -> base[index] = 0 }
                        base[2] = 1
                    }
                    4 -> {
                        score += base.sum() + 1
                        repeat(3) { index -> base[index] = 0 }
                    }
                }
                start = (start + 1) % 9
            }
            repeat(3) { index -> base[index] = 0 }
            out = 0
        }
        answer = answer.coerceAtLeast(score)
    }
    fun search(cur: Int, cnt: Int) {
        if (cnt == 8) {
            play()
            return
        }
        repeat(9) loop@{
            if (check[it]) return@loop
            check[it] = true
            order[cur] = it
            if (cur == 2) search(cur + 2, cnt + 1)
            else search(cur + 1, cnt + 1)
            check[it] = false
        }
    }
    search(0, 0)
    bw.write("$answer")
    bw.close()
}