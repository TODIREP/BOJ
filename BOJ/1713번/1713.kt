data class Post(val time: Int, var recommend: Int, val num: Int)

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    br.readLine().toInt()
    val list = mutableListOf<Post>()
    val comparable = Comparator { a: Post, b: Post ->
        if (a.recommend == b.recommend) a.time - b.time
        else a.recommend - b.recommend
    }
    br.readLine().split(" ").map(String::toInt).forEachIndexed { idx, value ->
        var notFound = true
        repeat(list.size) {
            if (list[it].num == value) {
                notFound = false
                list[it].recommend++
            }
        }
        if (notFound) {
            if (list.size < n) list.add(Post(idx, 1, value))
            else {
                list.sortWith(comparable)
                list[0] = Post(idx, 1, value)
            }
        }
    }
    list.sortedBy { it.num }.forEach { bw.write("${it.num} ") }
    bw.close()
}