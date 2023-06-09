﻿using System;
using System.Collections.Generic;
using System.Linq;
using Advanced.Algorithms.DataStructures;
using Advanced.Algorithms.DataStructures.Graph;

namespace Advanced.Algorithms.Graph;

/// <summary>
///     A* algorithm implementation using Fibonacci Heap.
/// </summary>
public class AStarShortestPath<T, TW> where TW : IComparable
{
    private readonly IAStarHeuristic<T, TW> heuristic;
    private readonly IShortestPathOperators<TW> @operator;

    public AStarShortestPath(IShortestPathOperators<TW> @operator, IAStarHeuristic<T, TW> heuristic)
    {
        this.@operator = @operator;
        this.heuristic = heuristic;
    }

    /// <summary>
    ///     Search path to target using the heuristic.
    /// </summary>
    public ShortestPathResult<T, TW> FindShortestPath(IGraph<T> graph, T source, T destination)
    {
        if (@operator == null)
            throw new ArgumentException("Provide an operator implementation for generic type W during initialization.");

        if (!graph.IsWeightedGraph)
            if (@operator.DefaultValue.GetType() != typeof(int))
                throw new ArgumentException("Edges of unweighted graphs are assigned an imaginary weight of one (1)." +
                                            "Provide an appropriate IShortestPathOperators<int> operator implementation during initialization.");

        //regular argument checks
        if (graph?.GetVertex(source) == null || graph.GetVertex(destination) == null) throw new ArgumentException();

        //track progress for distance to each Vertex from source
        var progress = new Dictionary<T, TW>();

        //trace our current path by mapping current vertex to its Parent
        var parentMap = new Dictionary<T, T>();

        //min heap to pick next closest vertex 
        var minHeap = new FibonacciHeap<AStarWrap<T, TW>>();
        //keep references of heap Node for decrement key operation
        var heapMapping = new Dictionary<T, AStarWrap<T, TW>>();

        //add vertices to min heap and progress map
        foreach (var vertex in graph.VerticesAsEnumberable)
        {
            //init parent
            parentMap.Add(vertex.Key, default);

            //init to max value
            progress.Add(vertex.Key, @operator.MaxValue);

            if (vertex.Key.Equals(source)) continue;
        }

        //start from source vertex as current 
        var current = new AStarWrap<T, TW>(heuristic, destination)
        {
            Distance = @operator.DefaultValue,
            Vertex = source
        };

        //insert neighbour in heap
        minHeap.Insert(current);
        heapMapping[source] = current;

        //until heap is empty
        while (minHeap.Count > 0)
        {
            //next min vertex to visit
            current = minHeap.Extract();
            heapMapping.Remove(current.Vertex);

            //no path exists, so return max value
            if (current.Distance.Equals(@operator.MaxValue))
                return new ShortestPathResult<T, TW>(null, @operator.MaxValue);

            //visit neighbours of current
            foreach (var neighbour in graph.GetVertex(current.Vertex).Edges
                         .Where(x => !x.TargetVertexKey.Equals(source)))
            {
                //new distance to neighbour
                var newDistance = @operator.Sum(current.Distance,
                    graph.GetVertex(current.Vertex).GetEdge(neighbour.TargetVertex).Weight<TW>());

                //current distance to neighbour
                var existingDistance = progress[neighbour.TargetVertexKey];

                //update distance if new is better
                if (newDistance.CompareTo(existingDistance) < 0)
                {
                    progress[neighbour.TargetVertexKey] = newDistance;

                    if (heapMapping.ContainsKey(neighbour.TargetVertexKey))
                    {
                        //decrement distance to neighbour in heap
                        var decremented = new AStarWrap<T, TW>(heuristic, destination)
                        {
                            Distance = newDistance,
                            Vertex = neighbour.TargetVertexKey
                        };

                        minHeap.UpdateKey(heapMapping[neighbour.TargetVertexKey], decremented);
                        heapMapping[neighbour.TargetVertexKey] = decremented;
                    }
                    else
                    {
                        //insert neighbour in heap
                        var discovered = new AStarWrap<T, TW>(heuristic, destination)
                        {
                            Distance = newDistance,
                            Vertex = neighbour.TargetVertexKey
                        };

                        minHeap.Insert(discovered);
                        heapMapping[neighbour.TargetVertexKey] = discovered;
                    }

                    //trace parent
                    parentMap[neighbour.TargetVertexKey] = current.Vertex;
                }
            }
        }

        return TracePath(graph, parentMap, source, destination);
    }

    /// <summary>
    ///     Trace back path from destination to source using parent map.
    /// </summary>
    private ShortestPathResult<T, TW> TracePath(IGraph<T> graph, Dictionary<T, T> parentMap, T source, T destination)
    {
        //trace the path
        var pathStack = new Stack<T>();

        pathStack.Push(destination);

        var currentV = destination;
        while (!Equals(currentV, default(T)) && !Equals(parentMap[currentV], default(T)))
        {
            pathStack.Push(parentMap[currentV]);
            currentV = parentMap[currentV];
        }

        //return result
        var resultPath = new List<T>();
        var resultLength = @operator.DefaultValue;
        while (pathStack.Count > 0) resultPath.Add(pathStack.Pop());

        for (var i = 0; i < resultPath.Count - 1; i++)
            resultLength = @operator.Sum(resultLength,
                graph.GetVertex(resultPath[i]).GetEdge(graph.GetVertex(resultPath[i + 1])).Weight<TW>());

        return new ShortestPathResult<T, TW>(resultPath, resultLength);
    }
}

/// <summary>
///     Search heuristic used by A* search algorithm.
/// </summary>
public interface IAStarHeuristic<T, TW> where TW : IComparable
{
    /// <summary>
    ///     Return the distance to target for given sourcevertex as computed by the hueristic used for A* search.
    /// </summary>
    TW HueristicDistanceToTarget(T sourceVertex, T targetVertex);
}

//Node for our Fibonacci heap
internal class AStarWrap<T, TW> : IComparable where TW : IComparable
{
    private readonly T destinationVertex;
    private readonly IAStarHeuristic<T, TW> heuristic;

    internal AStarWrap(IAStarHeuristic<T, TW> heuristic, T destinationVertex)
    {
        this.heuristic = heuristic;
        this.destinationVertex = destinationVertex;
    }

    internal T Vertex { get; set; }
    internal TW Distance { get; set; }

    //compare distance to target using the heuristic provided
    public int CompareTo(object obj)
    {
        if (this == obj) return 0;

        var result1 = heuristic.HueristicDistanceToTarget(Vertex, destinationVertex);
        var result2 = heuristic.HueristicDistanceToTarget((obj as AStarWrap<T, TW>).Vertex, destinationVertex);

        return result1.CompareTo(result2);
    }
}