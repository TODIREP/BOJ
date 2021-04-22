fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, r, q) = br.readLine().split(" ").map(String::toInt)
    val link = Array(n) { mutableListOf<Int>() }
    repeat(n - 1) {
        val (u, v) = br.readLine().split(" ").map(String::toInt)
        link[u - 1].add(v - 1)
        link[v - 1].add(u - 1)
    }
    val visit = BooleanArray(n) { false }
    val node = Array(n) { mutableListOf<Int>() }
    val next = Array(n) { -1 }
    fun connect(cur: Int): Int {
        if (next[cur] != -1) return next[cur]
        visit[cur] = true
        next[cur] = 1
        link[cur].forEach {
            if (!visit[it]) {
                node[cur].add(it)
                next[cur] += connect(it)
            }
        }
        return next[cur]
    }
    connect(r - 1)
    repeat(q) { bw.write("${next[br.readLine().toInt() - 1]}\n") }
    bw.close()
}