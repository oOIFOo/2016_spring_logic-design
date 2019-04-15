module firstFSM(
	input wire clk,
	input reset,
	input sequence_i,
	output reg ans 
);

localparam a = 4'b0000 ;
localparam b = 4'b0001 ;
localparam c = 4'b0010 ;
localparam d = 4'b0011 ;
localparam e = 4'b0100 ;
localparam f = 4'b0101 ;
localparam g = 4'b0110 ;
localparam h = 4'b0111 ;
localparam i = 4'b1000 ;
localparam j = 4'b1001 ;

reg presentState ;
reg nextState ;

always @ (posedge clk , posedge reset)
	begin
		if (reset)	presentState <= a;
		else if (clk)	presentState <= nextState ;
	end
	
always @ *
begin
	nextState = presentState ;
	ans = 1'b0 ;

	case(presentState)
	    a : if (sequence_i == d)   nextState = b ;
	    
	    b : if (sequence_i == b)   nextState = c ;
			else    nextState = a ;
	        
	    c : begin
				if (sequence_i == d)   
				
				begin
				
	    			ans = 1'b1 ;
	    			nextState = b;
					 
				end
	    		else    nextState = a ;
	    	end
	    	
	    default :               
	            begin
	            ans = 1'b0 ;
	            nextState = a ;
	            end
	            
	endcase
end
endmodule



module firstFSMTest;

				reg clk, reset;
				reg sequence_i;
				wire ans;

				initial
					begin
					clk = 1'b0 ;
					sequence_i = 1'b0;
					end

					initial
					begin
					reset = 1'b1 ;
					#30 reset = 1'b0 ;
					end

					initial
					begin
					#30     sequence_i = 4'b1000 ; 
					#20     sequence_i = 4'b0011 ; 
					#20     sequence_i = 4'b0001 ; 
					#20     sequence_i = 4'b0011 ; 
					#20     sequence_i = 4'b0000 ; 
					#20     sequence_i = 4'b0010 ; 
					#20     sequence_i = 4'b1001 ; 
					#20     sequence_i = 4'b0100 ; 
					#20     sequence_i = 4'b0101 ; 

					end


					firstFSM uut(.clk(clk),
					.reset(reset),
					.sequence_i(sequence_i),
					.ans(ans)
					);

				always #10 clk = ~clk;

				endmodule


