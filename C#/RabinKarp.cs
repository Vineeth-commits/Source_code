﻿using System;

namespace Advanced.Algorithms.String;

/// <summary>
///     A Rabin-Karp string search implementation.
/// </summary>
public class RabinKarp
{
    /// <summary>
    ///     Hard coding this, ideally should be a large prime
    ///     To reduce collisions.
    /// </summary>
    private const int PrimeNumber = 101;

    private readonly double tolerance = 0.00001;

    public int Search(string input, string pattern)
    {
        var patternHash = ComputeHash(pattern);
        var hash = ComputeHash(input.Substring(0, pattern.Length));

        if (Math.Abs(hash - patternHash) < tolerance)
            if (Valid(pattern, input.Substring(0, pattern.Length)))
                return 0;

        var lashHash = hash;

        for (var i = 1; i < input.Length - pattern.Length + 1; i++)
        {
            var newHash = ComputeHash(lashHash, pattern.Length, input[i - 1],
                input[i + pattern.Length - 1]);

            if (Math.Abs(newHash - patternHash) < tolerance)
                if (Valid(pattern, input.Substring(i, pattern.Length)))
                    return i;

            lashHash = newHash;
        }

        return -1;
    }


    /// <summary>
    ///     Returns true if matched hash string is same as the pattern.
    /// </summary>
    private bool Valid(string pattern, string match)
    {
        return pattern.Equals(match);
    }

    /// <summary>
    ///     Compute hash given a string.
    /// </summary>
    private double ComputeHash(string input)
    {
        double result = 0;
        for (var i = 0; i < input.Length; i++) result += input[i] * Math.Pow(PrimeNumber, i);

        return result;
    }

    /// <summary>
    ///     Compute hash given a newChar and last hash.
    /// </summary>
    private double ComputeHash(double lastHash, int patternLength,
        char removedChar, char newChar)
    {
        lastHash -= removedChar;
        var newHashHash = lastHash / PrimeNumber
                          + newChar * Math.Pow(PrimeNumber, patternLength - 1);

        return newHashHash;
    }
}