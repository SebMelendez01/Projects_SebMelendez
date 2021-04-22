import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class testPathSet {
	@Test
	void testIterator() {
	System.out.print(132);
	List<String> url1 = Arrays.asList(new String[] {"a"});
	List<String> url2 = Arrays.asList(new String[] {"a", "b", "c"});
	List<String> url3 = Arrays.asList(new String[] {"a", "b", "d"});
	List<String> url4 = Arrays.asList(new String[] {"a", "b", "a"});
	List<String> url5 = Arrays.asList(new String[] {"a", "c"});
	PathSet s = new PathSet();
	Assertions.assertTrue(s.isEmpty());
	/* OMITTED CODE */
	s.add(url1); 
	s.add(url2); 
	s.add(url3); 
	s.add(url4);
	s.add(url5); 
	
	Iterator<List<String>> it = s.iterator();
	Assertions.assertTrue(it.hasNext());
	Assertions.assertEquals(url1, it.next());
	Assertions.assertEquals(url4, it.next());
	Assertions.assertEquals(url2, it.next());
	Assertions.assertEquals(url3, it.next());
	Assertions.assertEquals(url5, it.next());
	Assertions.assertFalse(it.hasNext());
	Assertions.assertThrows(NoSuchElementException.class, () -> {it.next();});
	}
	
}



