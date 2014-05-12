// Copyright (c) 2014, Tamas Csala

import java.io.*;
import java.net.*;
import java.util.ArrayList;

public class Generate_GLerrors {
	public static int GetEndPos(int pos, StringBuilder line, BufferedReader br) {
		try {
			int div_depth = 1;

			while (div_depth > 0) {
				if (pos + 6 > line.length()) {
					line.append(br.readLine());
				}
				String str = line.substring(pos, pos + 6);
				if (str.startsWith("<div"))
					div_depth++;
				else if (str.startsWith("</div>"))
					div_depth--;
				pos++;
			}

			return pos;
	    } catch (IOException ioe) {
	         ioe.printStackTrace();
	    }
		return -1;
	}
	public static void ParseParagraph(ArrayList<String> strings,
									  BufferedReader br,
									  String line,
									  String id) {
		String current_string = new String();
		int start_pos = -1;
    	while ((start_pos = line.indexOf(id, start_pos + 1)) > 0) {
    		start_pos = line.indexOf('>', start_pos + id.length() + 1);
    		StringBuilder sb = new StringBuilder(line);
    		// It might also need to read in more to the string,
    		// and append to it. That's why I have to give
    		// a StringBuilder to it, not a string...
    		int end_pos = GetEndPos(start_pos, sb, br);
    		line = sb.toString();
    		boolean in_tag = false;
    		// The documentation's source has a lot of
    		// consecutive spaces in it, which do nothing in HTML...
    		boolean was_last_space = false;
    		for (int i = start_pos; i < end_pos; ++i) {
    			char chr = line.charAt(i);
    			if (chr == '<')
    				in_tag = true;
    			else if (chr == '>')
    				in_tag = false;
    			else {
    				if (!in_tag) {
						if (Character.isSpaceChar(chr) || chr == '\t') {
    						if (!was_last_space && !current_string.isEmpty()) {
    							current_string = current_string + ' ';
    						}
    						was_last_space = true;
    					} else {
    						if (chr == '&') {
    							if (i+4 > line.length()) {
    								try{
    									line += br.readLine();
    								} catch (IOException ioe) {
    								    ioe.printStackTrace();
    							    }
    							}
    							String next4 = line.substring(i, i + 4);
    							if (next4.startsWith("&gt;")) {
    								current_string = current_string + "> ";
    								was_last_space = true;
    								i += 3; // The for cycle will increment it too
    							} else if (next4.startsWith("&lt;")) {
    								current_string = current_string + "< ";
    								was_last_space = true;
    								i += 3; // The for cycle will increment it too
    							} else {
    								current_string = current_string + chr;
    								was_last_space = false;
    							}
    						} else if (chr == ';') {
								strings.add(current_string + chr);
    	    					current_string = new String();
    	    					was_last_space = false;
    						} else {
    							current_string = current_string + chr;
    							was_last_space = false;
    						}
    					}
    				} else if (line.substring(i - 1, i + 2).contains("<p>")) {
    					strings.add(current_string);
    					current_string = new String();
    					was_last_space = false;
    				}
    			}
    		}
    		strings.add(current_string);
			current_string = new String();
    	}
	}

	public static void ParsePage(PrintWriter writer, String glfunc) {
	    try {
	    	URL url = new URL("http://www.opengl.org/sdk/docs/man/xhtml/" + glfunc);
	    	BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()));

	    	String line;
	    	ArrayList<String> functions = new ArrayList<String>();
        	ArrayList<String> errors = new ArrayList<String>();

	        while ((line = br.readLine()) != null) {
	        	if (line.contains("funcsynopsis")) {
	        		ParseParagraph(functions, br, line, "funcsynopsis");
	        	} else if (line.contains("<h2>Errors</h2>")) {
	        		ParseParagraph(errors, br, line, "<h2>Errors</h2>");
	        	}
	        }

	        if (functions != null && errors != null) {
        		for (int i = 0; i != functions.size(); ++i) {
        			if (!functions.get(i).isEmpty()) {
            			// Print function signature
            			writer.println(functions.get(i));

    	        		// Print possible errors
    	        		for (int j = 0; j != errors.size(); ++j) {
    	        			if (!errors.get(j).isEmpty()) {
    	        				writer.println(errors.get(j));
    	        			}
    	        		}
    	        		writer.print('\n');
        			}
	        	}
        	}
	    } catch (MalformedURLException mue) {
	         mue.printStackTrace();
	    } catch (IOException ioe) {
	         ioe.printStackTrace();
	    }
	}

	public static void main(String[] args) {
	    try {
	    	String documentation_page = "http://www.opengl.org/sdk/docs/man/xhtml/index.html";
	    	System.out.println("Connecting to: " + documentation_page);
	    	URL url = new URL(documentation_page);
	    	BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()));
	    	PrintWriter writer = new PrintWriter("GLerrors.txt", "UTF-8");
	    	String line = null;
	    	int i = 0, num_pages = 0;

	    	// Get the number of pages - good to know, for the user...
	    	while ((line = br.readLine()) != null) {
	        	String anchor = "<tr><td><a target=\"pagedisp\" href=\"";
	        	if (line.contains(anchor)) {
	        		num_pages++;
	        	}
	        }
	    	// Reset the BufferedReader
	    	br = new BufferedReader(new InputStreamReader(url.openStream()));

	    	// Do the actual work
	        while ((line = br.readLine()) != null) {
	        	String anchor = "<tr><td><a target=\"pagedisp\" href=\"";
	        	int pos = line.indexOf(anchor);
	        	if (pos > 0) {
	        		int link_start = pos + anchor.length();
	        		int link_end = line.indexOf('"', link_start + 1);
	        		ParsePage(writer, line.substring(link_start, link_end));
	        		System.out.println("Number of pages parsed: " + (++i) + '/' + num_pages);
	        	}
	        }
	        writer.close();
	    } catch (MalformedURLException mue) {
	         mue.printStackTrace();
	    } catch (IOException ioe) {
	         ioe.printStackTrace();
	    } finally { }
	}
}
