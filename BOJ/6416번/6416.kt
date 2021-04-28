import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var cases = 1
    run loop@ {
        val tree = TreeMap<Int, Int>()
        while (true) {
            val line = StringTokenizer(br.readLine())
            while (line.hasMoreTokens()) {
                val u = line.nextToken().toInt()
                val v = line.nextToken().toInt()
                if (u == -1 && v == -1) return@loop
                if (u == 0 && v == 0) {
                    var valid = true
                    var root = 0
                    for (t in tree) {
                        if (t.value > 1) valid = false
                        else if (t.value == 0) root++
                    }
                    if (tree.size > 0 && root != 1) valid = false
                    tree.clear()
                    bw.write(
                        when (valid) {
                            true -> "Case $cases is a tree.\n"
                            false -> "Case $cases is not a tree.\n"
                        }
                    )
                    cases++
                    break
                }
                if (!tree.contains(u)) tree[u] = 0
                tree[v] = tree.getOrDefault(v, 0) + 1
            }
        }
    }
    bw.close()
}