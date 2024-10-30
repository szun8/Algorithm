using System;
using System.Collections.Generic;
using System.Linq;

public class SongInfo
{
    public int idx, count;
    public SongInfo() { }
    public SongInfo(int i, int c)
    {
        idx = i;
        count = c;
    }
}

public class Genre
{
    public int playCount;
    public List<SongInfo> songList;

    public Genre()
    {
        playCount = 0;
        songList = new List<SongInfo>();
    }

    public void Play(SongInfo song)
    {
        playCount += song.count;
        int idx = GetIdxOfBestSongs(song);

        if(idx != -1)
        {
            songList.Insert(idx, song);
        }

        if(songList.Count > 2)
        {
            songList.RemoveAt(songList.Count - 1);
        }
    }

    public int GetIdxOfBestSongs(SongInfo song)
    {
        for (int i = 0; i < songList.Count; i++)
        {
            if (songList[i].count < song.count)
            {
                return i;
            }
            else if (songList[i].count == song.count)
            {
                return songList[i].idx > song.idx ? i : i + 1;
            }
        }

        return songList.Count;
    }
}

public class Solution
{
    public Dictionary<string, Genre> rank = new Dictionary<string, Genre>();

    public int[] solution(string[] genres, int[] plays)
    {
        List<int> answer = new List<int>();

        for (int i = 0; i < genres.Length; i++)
        {
            if (!rank.ContainsKey(genres[i]))
                rank.Add(genres[i], new Genre());

            rank[genres[i]].Play(new SongInfo(i, plays[i]));
        }

        foreach (var data in rank.Values.OrderByDescending(e => e.playCount))
        {
            foreach (var song in data.songList)
            {
                answer.Add(song.idx);
            }
        }

        return answer.ToArray();
    }
}