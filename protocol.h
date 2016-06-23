@interface Question : NSObject

@property NSString *ID;	
@property NSString *text;
@property NSDate *creation_time;

@end

@interface Answer : NSObject

@property NSString *ID;	
@property NSString *text;
@property NSDate *creation_time;
@property NSString *ID_question;

@end
