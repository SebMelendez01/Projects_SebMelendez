import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Map.Entry;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Set;
import java.util.TreeMap;

public class PathSetNode {
	private TreeMap<String, PathSetNode> children;
	private boolean isLast;
	
	public PathSetNode() {
		this.children = new TreeMap<String, PathSetNode>();
		this.isLast = false;
	}
	public boolean isEmpty() {
		return (!this.isLast && children.isEmpty());
	}
/* adds path to the set. Does NOT mutate path */
	public void add(List<String> path) {		
		    int level = 0;
		    PathSetNode curr = this;
		    while (curr.children.containsKey(path.get(level))) {
		    	curr = curr.children.get(path.get(level));
		        level++;
		    }

		    for (int i = level; i < path.size(); i++) {
		        curr.children.put(path.get(level), new PathSetNode());
		        curr = curr.children.get(path.get(level));
		        level++;
		    }
		    curr.isLast = true;	
	}
	public boolean contains(List<String> path) { 
	    PathSetNode curr = this;
	    for (int i = 0; i < path.size(); i++) {
	        if (curr.children.containsKey(path.get(i))) {
	            curr = curr.children.get(path.get(i));
	        } else {
	            return false;
	        }
	    }
	    if (curr.isLast) {
	        return true;
	    } else {
	        return false;
	    }
	}
	public List<List<String>> toListOfPaths() { 
		List<List<String>> res = new ArrayList<>(); 
		List<String> urlRes = new ArrayList<>();
	    	new Object() {
	    		private void helper(PathSetNode child, List <String> urlList) {
	    			urlList.add(child.children.firstKey());
	    			if(child.isEmpty()) {
	    				res.add(urlList);
	    				return; 
	    			}
	    			
	    			if(child.isLast) {
	    				res.add(urlList);
	    				List<String> temp = new ArrayList<String>(urlList);  
	    				for(Map.Entry<String, PathSetNode> entry : child.children.entrySet()) {
	    					helper(entry.getValue(), temp);					
	    				}
	    			} else { 
	    				helper(child.children.get(child.children.firstKey()), urlList); 
	    			}
	   
	    		}
	    	}.helper(this, urlRes); 
	    return res; 
	}
} 

