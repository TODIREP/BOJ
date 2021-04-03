import java.util.*
class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {
        val dataSize = genres.size
        val genreList = Array(dataSize) { mutableListOf<Pair<Int, Int>>() }
        var genreCount = 0
        val genre = TreeMap<String, Int>()
        
        repeat(dataSize) { index ->
            var myIndex: Int
            when (genre.contains(genres[index])) {
                true -> myIndex = genre[genres[index]]!!
                false -> {
                    myIndex = genreCount++
                    genre[genres[index]] = myIndex
                }
            }
            genreList[myIndex].add(Pair(plays[index], index))
        }
        
        val genreSort = mutableListOf<Pair<Int, Int>>()
        for (g in genre) {
            var mySum = 0
            genreList[g.value].sortByDescending { it.first }
            
            for (play in genreList[g.value]) {
                mySum += play.first
            }
            genreSort.add(Pair(mySum, g.value))
        }
        
        genreSort.sortByDescending { it.first }
        var answer = mutableListOf<Int>()
        for (g in genreSort) {
            genreList[g.second].forEachIndexed { index, g -> 
                if (index < 2) {
                    answer.add(g.second)
                }
            }
        }
        return answer.toIntArray()
    }
}