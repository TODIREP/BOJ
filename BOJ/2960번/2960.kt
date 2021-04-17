fun main() {
    val (n, k) = readLine()!!.split(" ").map(String::toInt)
    val check = BooleanArray(n + 1) { false }
    fun find(): Int {
        var cnt = 0
        for (num in 2 until n + 1) {
            if (check[num]) continue
            cnt++
            if (cnt == k) return num
            var delta = 1
            while (num * ++delta <= n) {
                if (check[num * delta]) continue
                check[num * delta] = true
                cnt++
                if (cnt == k) return num * delta
            }
        }
        return 0
    }
    print("${find()}")
}